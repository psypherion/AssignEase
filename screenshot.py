from pynput import keyboard
import os
import shutil

class ScreenshotTaker:
    def __init__(self, directory_path, program_name, destination_path="temp/"):
        self.directory_path = directory_path
        self.program_name = program_name
        self.destination_path = destination_path
        self.old_items = []

    def current_screenshots(self):
        self.old_items = os.listdir(self.directory_path)
        return self.old_items
    
    def on_key_press(self, key):
        if key == keyboard.Key.print_screen:
            print("\nPrint Screen button pressed!")

    def on_key_release(self, key):
        char = getattr(key, 'char', '')  # Check if 'char' attribute is available
        if char == 's':  # Check for the 's' key
            print("\n's' key released. Press 'Enter' to continue...")
            return False

    def moving_screenshot(self):
        new_items = []
        for item in os.listdir(self.directory_path):
            if item not in self.old_items:
                new_items.append(item)
                shutil.move(
                    os.path.join(self.directory_path, item),
                    os.path.join(self.destination_path, f"{self.program_name}.jpg")
                )
        print("\nNew items:", new_items)

    def take_screenshot(self):
        with keyboard.Listener(on_press=self.on_key_press, on_release=self.on_key_release) as listener:
            print("\nPress the Print Screen button (or press 's' to exit)...")
            try:
                listener.join()
                # Wait for user to press 'Enter' to continue
                input("Press 'Enter' to continue...")
            except KeyboardInterrupt:
                pass
        return "Screenshot taken successfully!"

if __name__ == "__main__":
    screenshot_taker = ScreenshotTaker(directory_path="/home/s4ms3pi0l/Pictures/Screenshots/", 
                                       program_name="ohhyeahh")
    screenshot_taker.current_screenshots()
    screenshot_taker.take_screenshot()
    screenshot_taker.moving_screenshot()