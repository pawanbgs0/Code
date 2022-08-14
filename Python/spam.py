import pyautogui as py
import time

spam = 0

while spam < 1:
    py.typewrite("Spamer!")
    time.sleep(1)
    py.press("return")