from __future__ import annotations
from tester.event_tester import EventTester, ParticipantSummary
from pprint import pprint
from typing import List
import xlsxwriter


class Spreadsheet:
    def __init__(self, file_name: str, event: EventTester):
        self.file_name = file_name
        self.event = event
        self.workbook = xlsxwriter.Workbook(file_name)
        self.worksheet = self.workbook.add_worksheet()
        self.row = 0
        self.center_style = {"align": "center", "valign": "vcenter"}
        self.header_style = {
            "border": 2,
            "bold": True,
            "align": "left",
            "valign": "vcenter",
        }
        self.header_fmt = self.workbook.add_format(
            self.header_style
            | self.center_style
            | {"bg_color": "#FFFF00", "text_wrap": True, "font_size": 13}
        )
        self.test_name_cell = self.workbook.add_format(
            self.header_style
            | {
                "bg_color": "#FF0000",
                "color": "#FFFFFF",
                "font_size": 12,
                "align": "center",
            }
        )
        self.value_header_cell = self.workbook.add_format(
            self.header_style
            | {"bg_color": "#000000", "color": "#FFFFFF", "align": "center"}
        )

        self.red_cell_style = {"bg_color": "#FF0000"}
        self.blue_cell_style = {"bg_color": "#0000FF"}
        self.green_cell_style = {"bg_color": "#03AC13"}
        self.orange_cell_style = {"bg_color": "#E26B0A"}
        self.purple_cell_style = {"bg_color": "#A020F0"}

        self.result_style = {"bg_color": "#948A54", "color": "#FFFFFF", "bold": True}

    def draw_header(self):
        self.worksheet.merge_range(0, 0, 2, 0, "ID", self.header_fmt)
        self.worksheet.merge_range(0, 1, 2, 1, "Name", self.header_fmt)
        col = 2

        if not self.event.compile_only:
            for test in self.event.tests:
                self.worksheet.merge_range(
                    *[1, col, 1, col + 1],
                    test.name,
                    self.test_name_cell,
                )
                self.worksheet.write(2, col, "Status", self.value_header_cell)
                self.worksheet.write(2, col + 1, "Points", self.value_header_cell)
                col += 2

            self.worksheet.merge_range(
                *[0, 2, 0, col - 1],
                "Testovi",
                self.header_fmt,
            )
            self.worksheet.merge_range(
                *[0, col, 2, col],
                "Passed",
                self.header_fmt,
            )
            self.worksheet.merge_range(
                *[0, col + 1, 2, col + 1],
                "Total Points",
                self.header_fmt,
            )
        else:
            self.worksheet.merge_range(
                *[0, col, 2, col + 1],
                "Compiled Successfully",
                self.header_fmt,
            )
        self.worksheet.set_column(1, 1, 20)
        self.row = 3

    def get_center_format(self, **kwargs):
        return self.workbook.add_format(self.center_style | kwargs)

    def test_state_format(self, row, col, value, format):
        self.worksheet.conditional_format(
            *[3, 2, row, col - 1],
            {
                "type": "cell",
                "criteria": "==",
                "value": f'"{value}"',
                "format": self.workbook.add_format(
                    format | {"bold": True, "color": "#FFFFFF"}
                ),
            },
        )

    def set_test_state_formats(self, col):
        if self.event.compile_only:
            return
        self.test_state_format(self.row, col + 1, "PASSED", self.green_cell_style)
        self.test_state_format(self.row, col + 1, "FAILED", self.orange_cell_style)
        self.test_state_format(self.row, col + 1, "ERROR", self.red_cell_style)
        self.test_state_format(self.row, col + 1, "TIMEOUT", self.blue_cell_style)
        self.test_state_format(self.row, col + 1, "COMPILE", self.purple_cell_style)

    def set_borders(self, row, col):
        self.worksheet.conditional_format(
            *[2, 0, 2, col + 1],
            {
                "type": "formula",
                "criteria": "True",
                "format": self.workbook.add_format({"border": 2}),
            },
        )
        self.worksheet.conditional_format(
            *[3, 0, row - 1, 0],
            {
                "type": "formula",
                "criteria": "True",
                "format": self.workbook.add_format({"left": 1, "bottom": 1}),
            },
        )
        self.worksheet.conditional_format(
            *[3, col + 1, row - 1, col + 2],
            {
                "type": "formula",
                "criteria": "True",
                "format": self.workbook.add_format({"bottom": 1, "right": 1}),
            },
        )
        self.worksheet.conditional_format(
            *[3, 1, row - 1, col + 2],
            {
                "type": "formula",
                "criteria": "True",
                "format": self.workbook.add_format(
                    {"left": 1, "bottom": 1, "right": 1}
                ),
            },
        )

    def format(self, styles):
        return self.workbook.add_format(styles)

    def final_col(self):
        return 2 + 2 * len(self.event.tests) + 2

    def add_student_row(self, student):
        self.worksheet.write(
            *[self.row, 0],
            student.id,
            self.format(self.center_style | {"bold": True, "bg_color": "#C4D79B"}),
        )
        self.worksheet.write(
            *[self.row, 1],
            student.name,
            self.format(
                self.center_style
                | {"indent": 1, "bold": True}
                | {"bg_color": "#B7DEE8"}
                | {"color": "#002060"},
            ),
        )

        col = 2
        for result in student.results:
            self.worksheet.write_string(
                *[self.row, col], str(result.status), self.format(self.center_style)
            )
            self.worksheet.write_number(
                *[self.row, col + 1],
                result.points,
                self.format(
                    self.center_style | {"bg_color": "#FABF8F", "bold": True},
                ),
            )
            col += 2
        if not self.event.compile_only:
            self.worksheet.write_number(
                *[self.row, col],
                student.successes,
                self.format(self.center_style | self.result_style),
            )
            self.worksheet.write_number(
                *[self.row, col + 1],
                student.points,
                self.format(self.center_style | self.result_style),
            )
        else:
            self.worksheet.merge_range(
                *[self.row, col, self.row, col + 1],
                "Yes" if student.compilation_success else "No",
                self.format(
                    self.center_style | self.result_style | {"align": "center"}
                ),
            )

        self.row += 1

    def fill(self):
        self.results: List[ParticipantSummary] = self.event.get_results()

        self.draw_header()

        for student in self.results:
            self.add_student_row(student)

        self.set_test_state_formats(self.final_col() - 2)
        self.set_borders(self.row, self.final_col() - 2)

    def close(self):
        self.workbook.close()
