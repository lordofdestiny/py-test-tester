from __future__ import annotations
from tester.spreadsheet import Spreadsheet
from tester.event_tester import EventTester
from tester.language import Language
import xlsxwriter
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

try:
    spreadsheet = Spreadsheet(path, event)
    spreadsheet.fill()
    spreadsheet.close()
except xlsxwriter.exceptions.FileCreateError:
    print("Please close the Excel file before running the test script!")
