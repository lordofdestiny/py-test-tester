from __future__ import annotations
from tester.language import Language
from typing import List, Callable, Optional
from io import TextIOWrapper
from pathlib import Path
from os import path
import operator
import os

# Redundant
def get_tests_file(tests_dir: str, file_name: str = "tests.json") -> List[str]:
    path: Path = Path(os.getcwd(), tests_dir)
    string_dirs: List[str] = [str(dir) for dir in path.glob(f"**/{file_name}")]
    string_dirs.sort()
    return string_dirs


# Redundant
def check_compatible(in_files: List[str], out_files: List[str]) -> bool:
    if len(in_files) != len(out_files):
        return False

    strip_extension: Callable[[str], str]
    strip_extension = lambda file: path.splitext(file)[0]

    in_file_names = map(strip_extension, in_files)
    out_file_names = map(strip_extension, out_files)

    file_pairs = zip(in_file_names, out_file_names)

    return all(map(lambda pair: operator.eq(*pair), file_pairs))


# Redundant
def get_full_file_names(directory: str, rel_dir: str, files: List[str]) -> List[str]:
    root: List[str] = path.join(directory, rel_dir)
    return [path.join(root, file) for file in files]


# Redudant
def compare_files(directory, original, subject) -> Optional[List[bool]]:
    ofn: str = path.join(directory, original)
    sfn: str = path.join(directory, subject)

    from operator import ne

    r_open: Callable[[str], TextIOWrapper]
    r_open = lambda file: open(file, "r", encoding="utf-8")

    try:
        with r_open(ofn) as org_file, r_open(sfn) as sub_file:
            org_file: TextIOWrapper
            sub_file: TextIOWrapper
            return [ne(*lines) for lines in zip(org_file, sub_file)]
    except FileNotFoundError as error:
        print(error)
        return None


# Redudant
def get_sources(soruce_dir: List[str], language: Language) -> List[str]:
    return [
        os.path.join(soruce_dir, file)
        for file in os.listdir(soruce_dir)
        if os.path.splitext(file)[-1] in language.extensions
    ]
