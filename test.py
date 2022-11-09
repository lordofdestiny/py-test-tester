from __future__ import annotations
from tester.spreadsheet import generate_spreadsheet
from tester.event_tester import EventTester
from tester.language import Language
from typing import List
import os


Language.set_directory("languages")

settings = {
    "root_dir": os.getcwd(),
    "tests_dir": "tests",
    "sources_dir": "sources",
    "logs_dir": "outputs/logs",
    "executables_dir": "outputs/executables",
}

event: EventTester = EventTester("c", settings)
event.test_all()


print(f"Testing done! Students tested: {len(event.participants)}")
path: str = os.path.join(event.logs_dir, "results.xlsx")

generate_spreadsheet(path, event)
