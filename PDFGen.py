import PyPDF2
import os
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
from reportlab.lib.units import inch
from reportlab.lib.utils import ImageReader

class ContentReader:
    @staticmethod
    def read_c_file(file_path, text):
        try:
            with open(file_path, 'r') as file:
                content = file.read()
                pdf_content = f"{text}\n{content}"
                return pdf_content
        except FileNotFoundError:
            print(f"File '{file_path}' not found.")
            return None

class PDFGenerator:
    def __init__(self, file_name, content_reader, text, content_path, image_path=None):
        self.file_name = file_name
        self.content_reader = content_reader
        self.content_path = content_path
        self.image_path = image_path
        self.pdf_path = f"pdf_files/{file_name}.pdf"
        self.text = text

    def create_pdf(self):
        text_content = self.content_reader.read_c_file(self.content_path, self.text)
        if text_content is not None:
            c = canvas.Canvas(self.pdf_path, pagesize=letter)
            c.setFont("Courier", 6)
            lines = text_content.split('\n')
            y_position = letter[1] - inch

            for line in lines:
                if y_position <= inch:
                    # If there's not enough space on the current page, add a new page
                    c.showPage()
                    c.setFont("Courier", 8)
                    y_position = letter[1] - inch

                c.drawString(inch, y_position, line)
                y_position -= 7

            # Check if image needs to be added on an additional page
            if y_position <= inch and self.image_path:
                self._add_image_on_additional_page(c)
            elif self.image_path:
                # Add image on the current page if there's enough space
                img = ImageReader(self.image_path)
                img_width = inch * 6.69
                img_height = inch * 4
                c.drawImage(img, inch, y_position - img_height, width=img_width, height=img_height)

            c.save()
            print(f"PDF '{self.pdf_path}' created successfully.")


    def _add_image_on_additional_page(self, canvas_obj):
        if self.image_path:
            img = ImageReader(self.image_path)
            img_width = inch * 6.69
            img_height = inch * 4

            # Create a new page
            canvas_obj.showPage()
            canvas_obj.setFont("Courier", 6)

            # Draw the image on the new page
            canvas_obj.drawImage(img, inch, letter[1] - img_height, width=img_width, height=img_height)

            print("Image added on an additional page.")

class PDFMerger:
    def __init__(self, input_folder, output_file):
        self.input_folder = input_folder
        self.output_file = output_file
        self.pdf_writer = PyPDF2.PdfWriter()

    def merge_pdfs(self):
        pdf_files = [f for f in os.listdir(self.input_folder) if f.endswith(".pdf")]
        pdf_files.sort(key=lambda x: int(x.split('_')[0]))

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
    Example usage for PDFGenerator with C file and ContentReader
    c_program_path = "/home/s4ms3pi0l/Documents/AssignEase/C_Programs/1_simple-compound.c"
    image_path = "/home/s4ms3pi0l/Documents/AssignEase/temp/1_simple-compound.jpg"

    pdf_generator = PDFGenerator(
        file_name="c_program_sample",
        content_reader=ContentReader,
        content_path=c_program_path,
        text="ohyeah",
        image_path=image_path
    )
    pdf_generator.create_pdf()
    merger = PDFMerger(
        input_folder="pdf_files",
        output_file="Assignment.pdf"
    )
    merger.merge_pdfs()
