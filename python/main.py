from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

service=Service(executable_path="C:\\Users\\Lakshin Khurana\\vs-code-files\\python\\chromedriver.exe")
driver=webdriver.Chrome(service=service)

driver.get("https://www.google.com")

input_element=driver.find_element(By.NAME,"q")
input_element.send_keys("very cool guy"+ Keys.enter)

time.sleep(10)

driver.quit()