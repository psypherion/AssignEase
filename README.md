# AssignEase

AssignEase is a tool designed to streamline the process of handling assignments by automating the execution and documentation of code-related tasks.

## Features
- **Question Matching**: Automatically match questions from a provided docx file with corresponding C programs.
- **Code Compilation and Execution**: Compile and run C programs, capturing the output for each question.
- **Screenshot Capture**: Take screenshots of the output for documentation.
- **PDF Generation**: Generate PDF files containing both the code and screenshots for each question.
- **PDF Merging**: Combine individual PDFs into a single assignment document.

## Getting Started

### Prerequisites
Ensure you have the necessary dependencies installed by running:
```bash
pip install -r requirements.txt
```

## Usage
1. ### Clone the repository:
   ```bash
   git clone https://github.com/ky13-troj/AssignEase.git
   ````
   ```bash
   cd AssignEase
   ```
2. ### Execute the main Script :
   ```bash
   python main.py
   ```
3. ### Follow the prompts to select the docx file, C programs directory, and screenshot directory.
4. ### The tool will automatically compile, run, and document each question, creating PDF files.
5. ### Merged PDFs will be saved in the Assignment.pdf file.

## Requirements
- docx
- os
- pynput
- shutil
- subprocess
- PySimpleGUI
- PyPDF2
- reportlab
- platform
  
## Future Goals :
1. Adding Auto Comment Feature
   
## Contributing

We welcome contributions from the community! If you'd like to contribute to this project, please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and ensure tests pass.
4. Submit a pull request, clearly describing the changes you made.

### Code Style

Please follow the [PEP 8](https://www.python.org/dev/peps/pep-0008/) style guide for Python code.

### Bug Reports and Feature Requests

If you encounter any issues or have ideas for new features, please [open an issue](https://github.com/ky13-troj/AssignEase/issues) on GitHub.

## License

This project is licensed under the [MIT License](LICENSE). By contributing, you agree that your contributions will be licensed under this license.

