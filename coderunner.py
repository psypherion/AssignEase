import subprocess

class CProgramCompiler:
    def __init__(self, program_path, executables_directory):
        self.program_path = program_path
        self.executables_directory = executables_directory

    def compile_and_run(self):
        executable = self._get_executable_name()
        print(executable)
        print(self.program_path)
        process = subprocess.Popen(["gcc", "-o", executable, self.program_path, "-lm"],
                                   stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        process.communicate()

        if process.returncode == 0:
            print("\nCompilation successful.\n\n\n")
            subprocess.call([f"./{executable}"])
        else:
            print("\nCompilation failed.")

    def _get_executable_name(self):
        return f"{self.executables_directory}/{self.program_path.split('/')[-1].split('.')[0]}"

