import os

class QuestionMatcher:
    def __init__(self, text_file, programs_directory):
        self.text_file = text_file
        self.programs_directory = programs_directory
        self.text_content = self.read_text_from_text()
        self.c_programs = self.programs()

    def read_text_from_text(self):
        with open(self.text_file, "r") as file:
            text = file.readlines()
        return text

    def questions(self):
        question_arr = []
        for i in range(len(self.text_content)):
            if "." in self.text_content[i]:
                question_arr.append(self.text_content[i])
        return question_arr

    def extract_numeric_prefix(self, program_name):
        try:
            return int(program_name.split('_')[0])
        except ValueError:
            return 0

    def programs(self):
        programs_list = os.listdir(self.programs_directory)
        c_programs = []
        for i in range(len(programs_list)):
            if f"{i}_" and ".c" in programs_list[i]:
                c_programs.append(programs_list[i])
        c_programs = sorted(c_programs, key=self.extract_numeric_prefix)
        return c_programs

    def match_questions_with_programs(self):
        question_num = len(self.c_programs)
        return self.questions()[:question_num]

    def matched_questions(self):
        matched_questions = self.match_questions_with_programs()
        ques_arr = []
        for questions in matched_questions:
            ques_arr.append(questions.split("\n")[0])
        return ques_arr
    
    def programs_paths(self):
        programs_paths = []
        for i in range(len(self.c_programs)):
            programs_paths.append(os.path.join(self.programs_directory, self.c_programs[i]))
        return programs_paths
    
if __name__ == "__main__":
    text_file_path = "Questions.txt"
    programs_directory_path = "C_programs"
    
    matcher = QuestionMatcher(text_file_path, programs_directory_path)
    matched_questions = matcher.match_questions_with_programs()
    print(matcher.programs_paths())
    print(matched_questions)
