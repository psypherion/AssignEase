import os
from docx import Document

class DocxToTextConverter:
    def __init__(self, docx_file_path):
        self.docx_file_path = docx_file_path
        self.text_content = self.read_text_from_docx()
        self.text_file_path = self.text_file_path()

    def read_text_from_docx(self):
        doc = Document(self.docx_file_path)
        text = ""
        count = 0
        for paragraph in doc.paragraphs:
            if len(paragraph.text) > 0:
                count += 1
                if count == 1:
                    text += paragraph.text + "\n"
                else:
                    text += f"{count-1}."+paragraph.text + "\n"
        return text

    def create_text_file(self, text_file_path="Questions.txt"):
        with open(text_file_path, "w") as file:
            file.write(self.text_content)
        return "{text_file_path} created successfully".format(text_file_path=text_file_path)
        
    def text_file_path(self):
        self.text_file_path
        return self.text_file_path
