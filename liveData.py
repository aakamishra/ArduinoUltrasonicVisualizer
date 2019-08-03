import serial
import math
import numpy  # Import numpy
import matplotlib.pyplot as plt #import matplotlib library
import csv
import numpy as np

xCoord = []
yCoord =[]
distanceData = []
steps = []
arduinoData = serial.Serial('/dev/ttyACM0') #Creating our serial object named arduinoData
cnt=0


with open('ultrasonic_file.csv', mode='w') as ultrasonic_file:
        data_writer = csv.writer(ultrasonic_file)
        while (cnt < 2048): # While loop that loops forever
            arduinoString = arduinoData.readline() #read the line of text from the serial port
            aData = arduinoString.split(",")
            distanceData.append(float(aData[1]))
            steps.append(float(aData[0]))
            cnt=cnt+1
                      #This allows us to just see the last 50 data points
        for i in range(10,len(distanceData)):
            yCoord.append(math.sin(steps[i]*3.1415/2048)*distanceData[i])
            xCoord.append(math.cos(steps[i]*3.1415/2048)*distanceData[i])


plt.scatter(xCoord, yCoord)
plt.show()

