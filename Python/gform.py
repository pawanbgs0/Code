import pyautogui
import time

time.sleep(5)

while True:
    pyautogui.press('tab')
    pyautogui.press('tab')
    pyautogui.press('tab')
    pyautogui.press('space')
    pyautogui.press('tab')
    pyautogui.press('tab')
    pyautogui.press('return')
    #wait
    time.sleep(5)
    pyautogui.hotkey('alt', 'left')
    time.sleep(1)

# while True:
#     pyautogui.write('INDIA')
#     pyautogui.press('return') 
    