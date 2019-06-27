# -*- coding:utf-8 -*-

'''
  # AutoMeasure.py
  #
  # Connect board with raspberryPi.
  # Make board power and URM09 connection correct.
  # Run this demo.
  #
  # Set the i2c communication device number.
  # Set test mode and distance.
  # Get temperature and distance data.
  #
  # Copyright   [DFRobot](http://www.dfrobot.com), 2016
  # Copyright   GNU Lesser General Public License
  #
  # version  V1.0
  # date  2019-6-25
'''

import sys
sys.path.append("../..")
import URM09
import time

''' Create a URM09 object to communicate with I2C. '''
URM09 = URM09.DFRobot_URM09()
''' Set the i2c device number  '''
URM09.begin(0x11)
time.sleep(0.1)

'''
   # The module is configured in automatic mode or passive
   #  _MEASURE_MODE_AUTOMATIC        // automatic mode
   #  _MEASURE_MODE_PASSIVE          // passive mode
   
   # The measurement distance is set to 500,300,100 
   #  _MEASURE_RANG_500              // Ranging from 500 
   #  _MEASURE_RANG_300              // Ranging from 300 
   #  _MEASURE_RANG_150              // Ranging from 100
''' 
URM09.SetModeRange(URM09._MEASURE_MODE_AUTOMATIC ,URM09._MEASURE_RANG_500)

while(1):
  time.sleep(0.1)
  ''' Read distance register '''
  dist = URM09.i2cReadDistance()
  ''' Read temperature register '''
  temp = URM09.i2cReadTemperature()
  
  print("Temperature is %.2f .c    " %(temp / 10))
  print("Distance is %d cm         " %dist)
  time.sleep(0.1)
