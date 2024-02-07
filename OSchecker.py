import platform

class OSChecker:
    def __init__(self):
        self.current_os = platform.system()

    def check_os(self):
        if self.current_os == "Windows":
            print("Running on Windows.")
            return "win"

        elif self.current_os == "Linux":
            print("Running on Linux.")
            return "lin"

        else:
            print(f"Unsupported operating system: {self.current_os}")
            return self.current_os

if __name__ == "__main__":
    os_checker = OSChecker()
    os_checker.check_os()
