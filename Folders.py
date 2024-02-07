import os

class FolderCreator:
    def __init__(self, folders=["data", "executables", "pdf_files", "temp"]):
        self.folders = folders

    def create_folders(self):
        for folder_path in self.folders:
            os.makedirs(folder_path, exist_ok=True)

if __name__ == "__main__":
    folder_creator = FolderCreator()
    folder_creator.create_folders()
