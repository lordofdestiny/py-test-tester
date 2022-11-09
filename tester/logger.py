from __future__ import annotations
import os


class Logger:
    def __init__(self, path):
        self.path = path
        self.file = None
        self.opened = False
        self.closed = False

    def open(self):
        if not self.opened and not self.closed:
            self.file = open(self.path, "w", encoding="utf-8")
            self.opened = True

    def close(self):
        if self.opened and not self.closed:
            self.file.close()
            self.opened = False
            self.closed = True
            self.file = None

    def log(self, *data, **kwargs):
        print(*data, **kwargs, file=self.file)

    def __enter__(self):
        self.open()
        return self

    def __exit__(self, *args):
        self.close()

    @staticmethod
    def make(directory, path):
        full_path_name = os.path.join(directory, path)
        log_path = os.path.dirname(full_path_name)

        if not os.path.exists(log_path):
            os.makedirs(log_path)

        return Logger(full_path_name)
