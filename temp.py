from questions import QuestionMatcher
from DOCText import DocxToTextConverter
from screenshot import ScreenshotTaker
from coderunner import CProgramCompiler
from PDFGen import PDFGenerator, PDFMerger, ContentReader
from ui import PathSelector
import os

def main():
    # Use PathSelector to get the paths for docx, c programs, and screenshots
    path_selector = PathSelector()
    docx_path, c_programs_path, screenshot_path = path_selector.get_paths()

    # Convert docx to text and create a text file
    ques_text = DocxToTextConverter(docx_path)
    text_file_directory = "data"
    if text_file_directory not in os.listdir():
        os.mkdir(text_file_directory)
    text_file_path = text_file_directory+"/Questions.txt"
    text_file_path = ques_text.create_text_file(text_file_path=text_file_path)
    # Match questions with programs
    ques = QuestionMatcher(text_file_path, c_programs_path)
    answered_questions = ques.matched_questions()
    program_paths = ques.programs_paths()

    # Create a directory for executables if it doesn't exist
    executables_directory = "executables"
    if executables_directory not in os.listdir():
        os.mkdir(executables_directory)

    # Compile and run programs, take screenshots, and move screenshots
    for i, program_path in enumerate(program_paths, start=1):
        print(f"\n\n------------------Question {i}------------------------\n\n"
              f"{answered_questions[i-1]}\n\n"
              f"-----------------------Answer-------------------------\n\n"
              f"Currently running Program: {program_path}\n\n"
              f"-----------------------XXX----------------------------\n\n")
        print("Press ctrl+c to stop the program\n\n")
        
        # Compile and run C programs
        compiler = CProgramCompiler(program_path=program_path, executables_directory=executables_directory)
        compiler.compile_and_run()
        
        # Take screenshots and move them
        screenshot_taker = ScreenshotTaker(directory_path=screenshot_path, program_name=f"{os.path.basename(program_path).split('.')[0]}.jpg")
        screenshot_taker.current_screenshots()
        screenshot_taker.take_screenshot()
        screenshot_taker.moving_screenshot()  

    # Generate PDFs for each program
    for i, program_path in enumerate(program_paths, start=1):
        pdf_generator = PDFGenerator(
            file_name=f"{os.path.basename(program_path).split('.')[0]}",
            content_path=program_path,
            content_reader=ContentReader,
            image_path=f"{screenshot_path}/{os.path.basename(program_path).split('.')[0]}.jpg"
        )
        pdf_generator.generate_pdf()

    # Merge PDFs into a single file
    pdf_merger = PDFMerger(input_folder="pdf_files", output_file="Assignment.pdf")
    pdf_merger.merge_pdf()

if __name__ == "__main__":
    main()
