from __future__ import annotations
from subprocess import CalledProcessError, TimeoutExpired
from typing import Any, List, Union, Optional, NoReturn
from io import TextIOWrapper
from itertools import chain
from operator import eq
from enum import Enum
from os import path
import json
import os


class TestParsingFailed(Exception):
    def __init__(self, field: str) -> None:
        self.field: str = field

    def __repr__(self) -> str:
        return f"Mandatory field '${self.field}' not found in the configuration file!\n"


class TestFileMissing(Exception):
    def __init__(self, file_name: str, stream_name: Optional[str] = None) -> None:
        self.stream_name: str = stream_name
        self.file_name: str = file_name

    def __repr__(self) -> str:
        if self.file_name is None:
            return f"File '{self.file_name}' not found!"
        else:
            return f"File '{self.file_name}' for *{self.stream_name}* not found!*"


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
            self.points: float = TestResult.calculate_points(test_case, self.stdout)

        self.status: TestStatus = self.calculate_status(test_case, test_output)

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
    def calculate_points(test: TestCase, output: Optional[str]) -> float:
        if test.expected_ostream is None:
            return test.points
        expected_lines: List[str] = [
            f"{x}\n" for x in test.expected_ostream.split("\n")
        ]
        output_lines: List[str] = [f"{x}\n" for x in output.split("\n")]

        if len(expected_lines) != len(output_lines):
            return 0

        ppl: float = test.points / len(expected_lines)

        points: float = sum(
            ppl for pair in zip(expected_lines, output_lines) if eq(*pair)
        )

        if points <= 0.5 * test.points:
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
    name_counter = 0

    def __init__(self, **kwargs) -> None:
        new_name: str = TestCase.next_name()
        self.name: str = new_name if kwargs["name"] is None else kwargs["name"]
        self.desc: str = kwargs["desc"]
        self.points: int = kwargs["points"]
        self.time_limit: float = kwargs["time_limit"]
        self.istream_name: str = kwargs["istream"]
        self.ostream_name: str = kwargs["ostream"]
        self.ifile_names: List[str] = kwargs["ifiles"]
        self.ofile_names: List[str] = kwargs["ofiles"]
        self.args: List[str] = kwargs["args"]

        if self.istream_name is not None and not os.path.exists(self.istream_name):
            raise TestFileMissing(self.istream_name, "istream")
        if self.istream_name is not None and not os.path.exists(self.ostream_name):
            raise TestFileMissing(self.ostream_name, "ostream")
        for file in chain(self.ifile_names, self.ofile_names):
            if not os.path.exists(file):
                raise TestFileMissing(file)

        self.expected_ostream: Optional[str] = None
        with open(self.ostream_name, "r", encoding="utf-8") as file:
            file: TextIOWrapper
            self.expected_ostream = file.read()

    @classmethod
    def next_name(cls) -> str:
        cls.name_counter += 1
        return f"test_{cls.name_counter}"

    def get_report(self, result: TestResult) -> str:
        match result.status:
            case TestStatus.PASSED:
                return "Output matches expected output."
            case TestStatus.ERROR:
                return (
                    f"Error(code={result.getReturnCode()}) encountered during execution:\n"
                    f"{result.stderr}"
                )
            case TestStatus.FAILED:
                return (
                    "Outputs do not match!!!\n"
                    "Expected:\n"
                    f"{self.expected_ostream}\n"
                    f"{'-' * 25}\n"
                    "But received:\n"
                    f"{result.stdout}"
                )
            case _:
                return "Test TIMEOUT"

    @staticmethod
    def loadTests(test_dir: str) -> List[TestCase]:
        test_file: str = path.join(test_dir, "tests.json")

        test_data: Optional[List[dict[str, Any]]] = None
        with open(test_file, "r") as file:
            file: TextIOWrapper
            test_data = json.load(file)

        return [
            TestCase.parseTest(test_dir, test)
            for test in test_data
            if not test.get("skip", False)
        ]

    @staticmethod
    def parseTest(root: str, test: dict[str, Any]) -> TestCase | NoReturn:
        if "directory" not in test:
            raise TestParsingFailed("directory")
        dir: str = path.join(root, test["directory"])

        streams: dict[str, str] = test.get("streams", {})
        istream: Optional[str] = None
        istream = path.join(dir, streams["input"]) if "input" in streams else None
        ostream: Optional[str] = None
        ostream = path.join(dir, streams["output"]) if "output" in streams else None

        files: str = test.get("files", {"input": [], "output": []})
        ifiles: List[str] = [path.join(dir, x) for x in files.get("input", [])]
        ofiles: List[str] = [path.join(dir, x) for x in files.get("output", [])]

        return TestCase(
            name=test.get("name", None),
            desc=test.get("description", "No Description"),
            points=test.get("points", 1),
            time_limit=test.get("tile_limit", 1),
            args=test.get("args", []),
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
