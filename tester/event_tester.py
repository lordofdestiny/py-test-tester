from __future__ import annotations
from tester.test_case import TestCase, TestResult, CompilationFailed
from tester.language import Language
from tester.program import Program
from tester.logger import Logger
from typing import List, Tuple, Optional
import shutil
import os


class TestRunner:
    def __init__(self, program: Program, working_dir, logger=None) -> None:
        self.program: Program = program
        self.working_dir = working_dir
        self.logger: Logger = logger
        self.log: bool = logger is not None

    def run_all(self, tests: List[TestCase]) -> List[TestResult]:
        return [self.run(test) for test in tests]

    def run(self, test):
        result = self.program.run(test, self.working_dir)

        if self.log:
            self.logger.log(f"{test.name}")
            self.logger.log(test.get_report(result))
            self.logger.log(f"{'*' * 40}")

        with os.scandir(self.working_dir) as entries:
            for entry in entries:
                if entry.is_dir() and not entry.is_symlink():
                    shutil.rmtree(entry.path)
                else:
                    os.remove(entry.path)

        return result


class Participant:
    def __init__(self, working_dir, source_file, executables_dir, logs_dir):
        self.working_dir = working_dir
        self.source_file: str = source_file
        self.id: str
        self.name: str
        self.name, self.id = Participant.parse_name(source_file)
        self.executable_file: str = os.path.join(
            executables_dir,
            f"{Participant.unique_name(self)}",
        )

        self.logs_file = os.path.join(
            logs_dir,
            f"{Participant.unique_name(self)}.txt",
        )
        self.results: List[TestResult] = []

    def get_successes(self) -> int:
        return sum(result.successful() for result in self.results)

    def get_points(self) -> float:
        return sum(result.points for result in self.results)

    def __str__(self) -> str:
        return f"{self.name}"

    @staticmethod
    def unique_name(participant: Participant) -> str:
        return f"{participant.name.replace(' ','')}_{participant.id}"

    @staticmethod
    def parse_name(source) -> Tuple[str, str]:
        file_name: str = os.path.basename(source)
        clean_name: str = os.path.splitext(file_name)[0]
        first_name, last_name, *split_id = clean_name.split("_")
        name: str = f"{first_name.capitalize()} {last_name.capitalize()}"
        id = "".join(split_id).replace("-", "")
        return name, id


class DirectoryNotFound(Exception):
    def __init__(self, path) -> None:
        self.path = path

    def __str__(self) -> str:
        return f"Directory '{self.path}' does not exist!"


class ParticipantSummary:
    def __init__(self, participant: Participant) -> None:
        self.id: str = participant.id
        self.name: str = participant.name
        self.successes: int = participant.get_successes()
        self.points: float = participant.get_points()
        self.results: List[TestResult] = participant.results


class EventTester:
    def __init__(self, langid: str, settings: dict[str, str]) -> None:
        self.langugage: Language = Language.get(langid)
        root = os.path.abspath(settings["root_dir"])
        self.root_dir: str = root
        self.sources_dir: str = os.path.join(root, settings["sources_dir"])
        self.executables_dir: str = os.path.join(root, settings["executables_dir"])
        self.tests_dir: str = os.path.join(root, settings["tests_dir"])
        self.logs_dir: str = os.path.join(root, settings["logs_dir"])
        self.working_dir: str = os.path.join(root, "workdir")
        self.results_cache: Optional[List[ParticipantSummary]] = None

        if not os.path.exists(self.tests_dir):
            raise FileNotFoundError(self.tests_dir)

        self.tests: List[TestCase] = TestCase.loadTests(self.tests_dir)

        if not os.path.exists(self.sources_dir):
            raise FileNotFoundError(self.sources_dir)

        self.participants: List[Participant] = [
            Participant(
                self.working_dir,
                source_files,
                self.executables_dir,
                self.logs_dir,
            )
            for source_files in self.__get_sources()
        ]

        if not os.path.exists(self.logs_dir):
            os.makedirs(self.logs_dir, exist_ok=True)

        if not os.path.exists(self.executables_dir):
            os.makedirs(self.executables_dir, exist_ok=True)

    def __get_sources(self) -> List[str]:
        return [
            os.path.join(self.sources_dir, file)
            for file in os.listdir(self.sources_dir)
            if os.path.splitext(file)[-1] in self.langugage.extensions
        ]

    def test_all(self) -> None:
        if not os.path.exists(self.working_dir):
            os.makedirs(self.working_dir, exist_ok=True)
        with os.scandir(self.working_dir) as entries:
            for entry in entries:
                if entry.is_dir() and not entry.is_symlink():
                    shutil.rmtree(entry.path)
                else:
                    os.remove(entry.path)
        for participant in self.participants:
            self.test_participant(participant)

        shutil.rmtree(self.working_dir)

    def test_participant(self, participant: Participant):
        try:
            program = Program(
                self.langugage,
                [participant.source_file],
                participant.source_file,
                participant.executable_file,
            )
            with Logger(participant.logs_file) as logger:
                logger: Logger

                runner = TestRunner(program, participant.working_dir, logger)
                participant.results: List[TestResult] = runner.run_all(self.tests)
                successes: int = participant.get_successes()
                points: float = participant.get_points()
                logger.log(f"{successes}/{len(self.tests)} tests passed!")
                logger.log(f"Total grade: " f"{points:.2f}")

        except CompilationFailed as error:
            participant.results = [TestResult(test, error) for test in self.tests]
            with Logger(participant.logs_file) as logger:
                logger: Logger
                logger.log(f"Compilation failed!")
                logger.log(f"Error: {error}")

    def get_results(self) -> List[ParticipantSummary]:
        if self.results_cache is None:
            self.results_cache = list(map(ParticipantSummary, self.participants))
        return self.results_cache
