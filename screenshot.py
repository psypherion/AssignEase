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

    def stop_listening(self, key):
        if key == keyboard.Key.enter:
            print("\nEnter key pressed. Now Press ctrl+c")
            self.stop_listening_flag = True
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
        with keyboard.Listener(on_press=self.on_key_press) as listener, \
                keyboard.Listener(on_press=self.stop_listening) as stop_listener:
            print("\nPress the Print Screen button (or press ctrl+c to exit)...")
            try:
                listener.join()
                stop_listener.join()
            except KeyboardInterrupt:
                pass
        return "Screenshot taken successfully!"

if __name__ == "__main__":
    screenshot_taker = ScreenshotTaker(directory_path="/home/s4ms3pi0l/Pictures/Screenshots/", 
                                       program_name="ohhyeahh")
    screenshot_taker.current_screenshots()
    screenshot_taker.take_screenshot()
    screenshot_taker.moving_screenshot()
