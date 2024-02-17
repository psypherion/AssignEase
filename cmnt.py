import re
import os
def extract_programs(text):
    # Use regular expression to extract program names and codes
    pattern = re.compile(r'(\d+_\S+)\n\n(.*?)(?=\d+_\S+|$)', re.DOTALL)
    matches = re.finditer(pattern, text)
    
    programs = []
    for match in matches:
        program_name = match.group(1)
        program_code = match.group(2).strip()
        programs.append((program_name, program_code))
    
    return programs

def create_c_files(programs, folder_name):
    # Create C files with the respective program names
    for program_name, program_code in programs:
        file_path = os.path.join(folder_name, f"{program_name}")
        with open(file_path, 'w') as file:
            file.write(program_code)

if __name__ == "__main__":
    file_path = input("Enter the path to the text file: ")
    folder_name = input("Enter the folder name to save C files: ")

    with open(file_path, 'r') as f:
        content = f.read()

    programs = extract_programs(content)

    if not os.path.exists(folder_name):
        os.makedirs(folder_name)

    create_c_files(programs, folder_name)

    print("C files created successfully.")
