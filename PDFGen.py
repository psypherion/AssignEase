import PyPDF2
import os
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
from reportlab.lib.units import inch
from reportlab.lib.utils import ImageReader

class ContentReader:
    @staticmethod
    def read_c_file(file_path):
        try:
            with open(file_path, 'r') as file:
                content = file.read()
                return content
        except FileNotFoundError:
            print(f"File '{file_path}' not found.")
            return None

class PDFGenerator:
    def __init__(self, file_name, content_reader, content_path, image_path=None):
        self.file_name = file_name
        self.content_reader = content_reader
        self.content_path = content_path
        self.image_path = image_path
        self.pdf_path = f"pdf_files/{file_name}.pdf"

    def create_pdf(self):
        text_content = self.content_reader.read_c_file(self.content_path)
        if text_content is not None:
            c = canvas.Canvas(self.pdf_path, pagesize=letter)
            c.setFont("Helvetica", 12)
            lines = text_content.split('\n')
            y_position = letter[1] - inch
            for line in lines:
                c.drawString(inch, y_position, line)
                y_position -= 14
                
            if self.image_path:
                img = ImageReader(self.image_path)
                img_width = inch * 6.69
                img_height = inch * 4
                c.drawImage(img, inch, y_position - img_height, width=img_width, height=img_height)
            c.save()
            print(f"PDF '{self.pdf_path}' created successfully.")

class PDFMerger:
    def __init__(self, input_folder, output_file):
        self.input_folder = input_folder
        self.output_file = output_file
        self.pdf_writer = PyPDF2.PdfWriter()

    def merge_pdfs(self):
        pdf_files = [f for f in os.listdir(self.input_folder) if f.endswith(".pdf")]
        pdf_files.sort()

        for pdf_file in pdf_files:
            pdf_path = os.path.join(self.input_folder, pdf_file)
            with open(pdf_path, 'rb') as pdf:
                pdf_reader = PyPDF2.PdfReader(pdf)
                for page_num in range(len(pdf_reader.pages)):
                    page = pdf_reader.pages[page_num]
                    self.pdf_writer.add_page(page)

        with open(self.output_file, 'wb') as output_pdf:
            self.pdf_writer.write(output_pdf)

        print(f'Merged PDFs saved to: {self.output_file}')
if __name__ == '__main__':
    # Example usage for PDFGenerator with C file and ContentReader
    c_program_path = "C_programs/sample.c"
    image_path = "temp/saxy.png"

    pdf_generator = PDFGenerator(
        file_name="c_program_sample",
        content_reader=ContentReader,
        content_path=c_program_path,
        image_path=image_path
    )
    pdf_generator.create_pdf()
