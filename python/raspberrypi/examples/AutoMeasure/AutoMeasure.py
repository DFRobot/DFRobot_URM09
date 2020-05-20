# -*- coding:utf-8 -*-
""" file AutoMeasure.py
  # @brief Automatic acquisition of distance and temperature
  # @n The distance and temperature are printed on the serial port
  #
  # @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  # @licence     The MIT License (MIT)
  # @author      ZhixinLiu(zhixin.liu@dfrobot.com)
  # version  V1.1
  # date  2020-5-20
  # @get from https://www.dfrobot.com
  # @url https://github.com/DFRobot/DFRobot_Sensor
"""
import sys
import time
sys.path.append("../..")
from DFRobot_URM09 import *

'''
   #The first  parameter is to select iic0 or iic1
   #The second parameter is the iic device address
'''
urm09 = DFRobot_URM09_IIC(1 ,0x11)
'''
   # The module is configured in automatic mode or passive
   #  _MEASURE_MODE_AUTOMATIC        // automatic mode
   #  _MEASURE_MODE_PASSIVE          // passive mode
   
   # The measurement distance is set to 500,300,150 
   #  _MEASURE_RANG_500              // Ranging from 500 
   #  _MEASURE_RANG_300              // Ranging from 300 
   #  _MEASURE_RANG_150              // Ranging from 150
''' 
urm09.set_mode_range(urm09._MEASURE_MODE_AUTOMATIC ,urm09._MEASURE_RANG_500)
while(1):
  time.sleep(0.1)
  ''' Read distance register '''
  dist = urm09.read_distance()
  ''' Read temperature register '''
  temp = urm09.read_temperature()
  print("Distance is %d cm         " %dist)
  print("Temperature is %.2f .c    " %temp)
  time.sleep(0.1)
