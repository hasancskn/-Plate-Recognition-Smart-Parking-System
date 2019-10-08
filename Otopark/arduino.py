import serial
import time

arduinoData = serial.Serial('COM4',9600)
time.sleep(1)

deger ='0'

while(1):



    f = open("plaka.txt", "r")
    deger = f.read(1)

    time.sleep(1)

    if(deger=='1'):

        arduinoData.write(deger)
    
        print("Durum:"+deger)

        time.sleep(5)

        arduinoData.write('0')

    if(deger=='0'):
        print("Durum:"+deger)
        arduinoData.write('0')

    time.sleep(2)


    


