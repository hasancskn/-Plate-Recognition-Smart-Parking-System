#-*-coding:utf-8-*-
from PIL import Image
import pytesseract
import cv2
import time
plakalar=["34 OFS 34"]

text = pytesseract.image_to_string(Image.open("arac1.jpg"))
for i in range (len(plakalar)):
    if (text==plakalar[i]):
        print("1231")
        durum=open("plaka.txt","w")
        durum.write("1")
        durum.close()
        time.sleep(1)
    else:
        durum=open("plaka.txt","w")
        durum.write("0")
        print("0")
        time.sleep(1)
        durum.close()

time.sleep(3)
durum=open("plaka.txt","w")
durum.write("0")
durum.close()

