from __future__ import annotations
from typing import List, NoReturn
from os import path
import json
import sys
import os


class UnsuportedLanguage(Exception):
    def __init__(self, lang: str) -> None:
        self.msg = f'Language "{lang}" is not supported on this platform.'

    def __repr__(self) -> str:
        return self.msg


class Language:
    languages_data: dict[str, Language] = {}
    languages_dir = None
    languages_loaded: bool = False

    def __init__(self, data):
        self.id: int = data["id"]
        self.name: str = data["name"]
        self.extensions: List[str] = data["extensions"]
        self.dontCompile: List[str] = data["dontCompile"]
        self.compiled: bool = data["compiled"]
        self.command: List[str] = data["environments"][Language.get_os()]["command"]
        self.compile: List[str] = data["environments"][Language.get_os()]["compile"]
        self.comiple_flags: List[str] = data["compile-flags"]
        self.version: List[int] = Language.unwind_version(data["min-version"])

    @staticmethod
    def set_directory(dir_name: str, load=False) -> None:
        root = os.getcwd()
        Language.languages_dir = path.join(root, dir_name)
        if load:
            Language.load_all()

    @staticmethod
    def load_all() -> None:
        for dir in os.scandir(Language.languages_dir):
            if not dir.is_dir() or dir.name.startswith("."):
                continue
            lang_path = path.join(dir.path, "environment.json")
            with open(lang_path, "r") as file:
                data = json.load(file)
                Language.languages_data[data["id"]] = Language(data)
        Language.languages_loaded = True

    @staticmethod
    def get_data(reload=False) -> dict[str, Language] | NoReturn:
        if Language.languages_dir is None:
            raise Exception("Languages directory not set!")
        if not Language.languages_loaded and not reload:
            Language.load_all()
        return Language.languages_data

    @staticmethod
    def get(lang: str) -> Language:
        return Language.get_data()[lang]

    @staticmethod
    def unwind_version(version) -> List[int]:
        return [int(d) for d in version.split(".")]

    @staticmethod
    def supported(language: str) -> bool:
        if not Language.languages_loaded:
            Language.load_all()
        if not language in Language.languages_data:
            return False
        return Language.get_os() in Language.languages_data[language].command

    def prepare_compile(self, files: list, target_name: str) -> List[str]:
        from os.path import splitext

        func = lambda file: splitext(file)[-1] not in self.dontCompile
        command: List[str] = [
            self.compile["name"],
            *self.compile["args"],
            *self.comiple_flags,
            *list(filter(func, files)),
        ]
        return [str.replace("$file", target_name) for str in command]

    def prepare_run(self, mainFile=None, target_name=None):
        command: List[str] = [self.command["name"], *self.command["args"]]
        command: List[str] = [str.replace("$file", target_name) for str in command]
        if not self.compiled and mainFile is not None:
            command.append(mainFile)
        return command

    @staticmethod
    def get_os():
        if sys.platform.startswith("win32"):
            return "windows"
        elif sys.platform.startswith("linux"):
            return "linux"
        elif sys.platform.startswith("darwin"):
            return "macos"
        else:
            return "unknown"
