import pyautogui
import time

time.sleep(5)

while True:
    pyautogui.write('INDIA')
    pyautogui.press('return') 
    






distance = 50

# while distance > 0:
#         pyautogui.drag(distance, 0, duration=0.5)   # move right
#         distance -= 5
#         pyautogui.drag(0, distance, duration=0.5)   # move down
#         pyautogui.drag(-distance, 0, duration=0.5)  # move left
#         distance -= 5
#         pyautogui.write("hello")
#         pyautogui.drag(0, -distance, duration=0.5)  # move up
