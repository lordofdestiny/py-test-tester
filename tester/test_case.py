from __future__ import annotations
from subprocess import CalledProcessError, TimeoutExpired
from typing import Any, List, Union
from io import TextIOWrapper
from operator import eq
from enum import Enum
from os import path
import json
import os


class TestStatus(Enum):
    PASSED = 0
    FAILED = 1
    ERROR = 2
    TIMEOUT = 3
    COMPILE = 4

    def __str__(self) -> str:
        return self.name


class TestResult:
    def getReturnCode(self) -> int:
        return self

    def __init__(
        self,
        test_case: TestCase,
        test_output: Union[CalledProcessError, ProgramTimeout, CompilationFailed],
    ) -> None:
        self.test_case: TestCase = test_case
        self.stdout: str = test_output.stdout
        self.stderr: str = test_output.stderr
        self.returncode: int = test_output.returncode
        self.points: float = 0

        if isinstance(test_output, ProgramTimeout):
            self.points = 0
        elif self.returncode != CompilationFailed.returncode:
            output_lines: List[str] = [f"{x}\n" for x in self.stdout.split("\n")]
            expected_lines: List[str] = [
                f"{x}\n" for x in test_case.expected_ostream.split("\n")
            ]
            self.points: float = TestResult.calculate_points(
                test_case.points,
                output_lines,
                expected_lines,
            )

        self.status: TestStatus = self.calculate_status(test_case, test_output)
        # elif not isinstance(test_output, CompilationFailed):
        #     self.status: TestStatus = self.calculate_status(test_case, test_output)
        #     self.points = (
        #         test_case.points
        #         if test_case.expected_ostream.strip() in self.stdout.strip()
        #         else 0
        #     )

    def calculate_status(
        self,
        test: TestCase,
        output: Union[CalledProcessError, ProgramTimeout, CompilationFailed],
    ) -> TestStatus:
        if isinstance(output, ProgramTimeout):
            return TestStatus.TIMEOUT
        elif isinstance(output, CompilationFailed):
            return TestStatus.COMPILE
        elif output.returncode != 0:
            return TestStatus.ERROR
        elif self.points == test.points:
            return TestStatus.PASSED
        else:
            return TestStatus.FAILED

    def successful(self) -> bool:
        return self.status == TestStatus.PASSED

    def __repr__(self) -> str:
        return (
            f"{self.status.name:>6} {self.test_case.name}:"
            f" {self.points:>6.2f}/{self.test_case.points:.2f}"
        )

    @staticmethod
    def calculate_points(
        total_points: float,
        expected: list[str],
        output: list[str],
    ) -> float:
        if len(expected) != len(output):
            return 0

        ppl: float = total_points / len(expected)

        points: float = sum(ppl for pair in zip(expected, output) if eq(*pair))

        if points <= 0.5 * total_points:
            return 0

        return points


class CompilationFailed(TestResult, Exception):
    returncode = 2**16 + 1

    def __init__(self, result: CalledProcessError) -> None:
        self.stdout: str = result.stdout
        self.stderr: str = result.stderr
        self.returncode: int = CompilationFailed.returncode

    def __repr__(self) -> str:
        return (
            f"Compilation failed with return code {self.returncode}.\n"
            f"Error message: {self.stderr}"
        )

    def __str__(self) -> str:
        return repr(self)


class ProgramTimeout(TestResult, Exception):
    returncode = 2**16 + 2

    def __init__(self, result: TimeoutExpired) -> None:
        self.stdout: str = result.stdout
        self.stderr: str = result.stderr
        self.returncode: int = ProgramTimeout.returncode

    def __repr__(self) -> str:
        return f"Program execution exceeded time limit.\n Error message: {self.stderr}"

    def __str__(self) -> str:
        return repr(self)


class TestCase:
    def __init__(self, **kwargs) -> None:
        self.name: str = kwargs["name"]
        self.desc: str = kwargs["desc"]
        self.skip: bool = kwargs["skip"]
        self.points: int = kwargs["points"]
        self.time_limit: float = kwargs["time_limit"]
        self.istream_name: str = kwargs["istream"]
        self.ostream_name: str = kwargs["ostream"]
        self.ifile_names: List[str] = kwargs["ifiles"]
        self.ofile_names: List[str] = kwargs["ofiles"]
        self.args: List[str] = kwargs["args"]
        with open(self.ostream_name, "r", encoding="utf-8") as file:
            file: TextIOWrapper
            self.expected_ostream = file.read()

    def get_report(self, result: TestResult) -> str:
        if result.status == TestStatus.PASSED:
            return "Output matches expected output!"
        elif result.status == TestStatus.ERROR:
            return (
                f"Error(code={result.getReturnCode()}) encountered during execution:\n"
                f"{result.stderr}"
            )
        else:
            return (
                "Outputs do not match!!!\n"
                "Expected:\n"
                f"{self.expected_ostream}\n"
                f"{'-' * 25}\n"
                "But received:\n"
                f"{result.stdout}"
            )

    @staticmethod
    def loadTests(test_dir: str) -> List[TestCase]:
        root: str = path.join(os.getcwd(), test_dir)
        test_file: str = path.join(root, "tests.json")

        test_data = None
        with open(test_file, "r") as file:
            file: TextIOWrapper
            test_data: dict[str, Any] = json.load(file)

        tests: List[TestCase] = [TestCase.parseTest(root, test) for test in test_data]

        return list(filter(lambda test: not test.skip, tests))

    @staticmethod
    def parseTest(root: str, test: dict[str, Any]) -> TestCase:
        dir: str = path.join(root, test["directory"])
        istream: str = path.join(dir, test["streams"]["input"])
        ostream: str = path.join(dir, test["streams"]["output"])
        ifiles: List[str] = [path.join(dir, x) for x in test["files"]["input"]]
        ofiles: List[str] = [path.join(dir, x) for x in test["files"]["output"]]

        return TestCase(
            name=test["name"],
            desc=test["description"],
            skip=test["skip"],
            points=test["points"],
            time_limit=test["time_limit"],
            args=test["args"],
            istream=istream,
            ostream=ostream,
            ifiles=ifiles,
            ofiles=ofiles,
        )

    def __repr__(self) -> str:
        return "TestCase: {} - {} - {}/{} - {}ms".format(
            self.name,
            self.desc,
            self.points,
            self.points,
            self.time_limit,
        )

    def __str__(self) -> str:
        return repr(self)
