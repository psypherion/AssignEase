import PySimpleGUI as sg
from tkinter import filedialog
import os

class PathSelector:
    def __init__(self):
        sg.theme('DarkGrey5')

    def get_path_from_browser(self, title, file_types=None, select_folders=False):
        layout = [
            [sg.Text(f'Select {title}'), sg.InputText(key='path'), sg.FileBrowse(file_types=file_types, initial_folder=os.getcwd()) if not select_folders else sg.FolderBrowse()],
            [sg.Button('OK'), sg.Button('Cancel')]
        ]

        window = sg.Window(title, layout)

        while True:
            event, values = window.read()

            if event == sg.WIN_CLOSED or event == 'Cancel':
                break

            if event == 'OK':
                path = values['path']
                window.close()
                return path

        window.close()

    def get_paths(self):
        docx_path = self.get_path_from_browser('Select Docx File', file_types=(("Docx Files", "*.docx"),))
        c_programs_path = self.get_path_from_browser('Select C Programs Directory', select_folders=True)
        screenshot_path = self.get_path_from_browser('Select Screenshot Directory', select_folders=True)

        return docx_path, c_programs_path, screenshot_path

if __name__ == '__main__':
    path_selector = PathSelector()
    docx_path, c_programs_path, screenshot_path = path_selector.get_paths()

    print(f'Docx Path: {docx_path}')
    print(f'C Programs Path: {c_programs_path}')
    print(f'Screenshot Path: {screenshot_path}')
