from __future__ import annotations
from tester.test_case import TestCase, TestResult, CompilationFailed, ProgramTimeout
from subprocess import CalledProcessError, TimeoutExpired, CompletedProcess
from tester.language import Language
from io import TextIOWrapper
from typing import Optional
import subprocess


class Compiler:
    def __init__(self, lang: Language):
        self.lang = lang

    def compile(self, sources, target_name):
        if not self.lang.compiled:
            return
        command = self.lang.prepare_compile(sources, target_name)
        try:
            result = subprocess.run(
                command,
                text=True,
                check=True,
                capture_output=True,
                encoding="utf-8",
            )
            if result.returncode != 0:
                raise CompilationFailed(result)
        except subprocess.CalledProcessError as e:
            raise CompilationFailed(e)
        except CompilationFailed:
            raise


class NoMainFile(Exception):
    def __init__(self):
        self.message

    def __repr__(self) -> str:
        return f"No main file specified!"


class Program:
    def __init__(self, lang: Language, files: list, mainFile, target_name) -> None:
        self.lang: Language = lang
        self.target_name = target_name
        if self.lang.compiled:
            self.compiler = Compiler(self.lang)
            self.compiler.compile(files, self.target_name)

        self.files = files
        self.ready = False
        self.command = self.lang.prepare_run(mainFile, self.target_name)

    def run(self, test_case: TestCase, working_dir) -> TestResult:
        try:
            istream: Optional[TextIOWrapper] = None
            if test_case.istream_name is not None:
                istream = open(test_case.istream_name)
            result: CompletedProcess[str] = subprocess.run(
                self.command + test_case.args,
                text=True,
                check=True,
                stdin=istream,
                cwd=working_dir,
                encoding="utf-8",
                capture_output=True,
                timeout=test_case.time_limit,
            )

            if istream is not None:
                istream.close()

        except CalledProcessError as error:
            result = error
        except TimeoutExpired as error:
            result = ProgramTimeout(error)
        return TestResult(test_case, result)
