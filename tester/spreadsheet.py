from __future__ import annotations
from tester.event_tester import EventTester, ParticipantSummary
from pprint import pprint
from typing import List
import xlsxwriter


def conditional_format(worksheet, row, column, value, format):
    worksheet.conditional_format(
        f"D2:{chr(ord('A')+column-1)}{row}",
        {
            "type": "cell",
            "criteria": "==",
            "value": f'"{value}"',
            "format": format,
        },
    )


def generate_spreadsheet(file_name: str, event: EventTester):
    results: List[ParticipantSummary] = event.get_results()
    if not len(results):
        return

    workbook = xlsxwriter.Workbook(file_name)
    worksheet = workbook.add_worksheet()

    merge_format = workbook.add_format({"align": "center", "valign": "vcenter"})
    header_cell = workbook.add_format(
        {
            "border": 1,
            "bold": True,
            "align": "left",
            "valign": "vcenter",
            "bg_color": "#FFFF00",
        }
    )
    red_cell = workbook.add_format({"bg_color": "#FF0000"})
    blue_cell = workbook.add_format({"bg_color": "#0000FF"})
    green_cell = workbook.add_format({"bg_color": "#03AC13"})
    orange_cell = workbook.add_format({"bg_color": "#FFA500"})
    purple_cell = workbook.add_format({"bg_color": "#A020F0"})

    worksheet.write(0, 0, "ID", header_cell)
    worksheet.write(0, 1, "Name", header_cell)
    column = 2

    for i, result in enumerate(results[0].results):
        worksheet.write(0, column, f"Test {i + 1}", header_cell)
        worksheet.write(0, column + 1, event.tests[i].name, header_cell)
        column += 2
    worksheet.write(0, column, "Passed", header_cell)
    worksheet.write(0, column + 1, "Total", header_cell)
    worksheet.set_column(1, 1, 20)

    row = 1
    for student in results:
        worksheet.merge_range(row, 0, row + 1, 0, student.id, merge_format)
        worksheet.merge_range(row, 1, row + 1, 1, student.name, merge_format)
        column = 2
        for i, result in enumerate(student.results):
            worksheet.write_string(row, column, f"Status")
            worksheet.write_string(row, column + 1, str(result.status))
            worksheet.write_string(row + 1, column, f"Points")
            worksheet.write_number(row + 1, column + 1, result.points)
            column += 2

        worksheet.merge_range(
            row,
            column,
            row + 1,
            column,
            f"{student.successes}/{len(event.tests)}",
            merge_format,
        )
        worksheet.merge_range(
            row,
            column + 1,
            row + 1,
            column + 1,
            student.points,
            merge_format,
        )
        row += 2

    conditional_format(worksheet, row, column + 1, "PASSED", green_cell)
    conditional_format(worksheet, row, column + 1, "FAILED", orange_cell)
    conditional_format(worksheet, row, column + 1, "ERROR", red_cell)
    conditional_format(worksheet, row, column + 1, "TIMEOUT", blue_cell)
    conditional_format(worksheet, row, column + 1, "COMPILE", purple_cell)

    workbook.close()
