# -*- coding:utf-8 -*-
'''!
  @file passive_measure.py
  @brief PassiveMeasure acquisition of distance and temperature
  @n The distance and temperature are printed on the serial port
  @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license The MIT License (MIT)
  @author ZhixinLiu(zhixin.liu@dfrobot.com)
  @version V1.1
  @date 2020-5-20
  @url https://github.com/DFRobot/DFRobot_URM09
'''
import sys
import time
sys.path.append("../")
from DFRobot_URM09 import *

IIC_MODE         = 0x01            # default use IIC1
IIC_ADDRESS      = 0x11            # default iic device address
'''
   The first  parameter is to select iic0 or iic1
   The second parameter is the iic device address
'''
urm09 = DFRobot_URM09_IIC(IIC_MODE, IIC_ADDRESS)

def setup():
  '''
     The module is configured in automatic mode or passive
        _MEASURE_MODE_AUTOMATIC        automatic mode
        _MEASURE_MODE_PASSIVE          passive mode
     The measurement distance is set to 500,300,150 
        _MEASURE_RANG_500              Ranging from 500 
        _MEASURE_RANG_300              Ranging from 300 
        _MEASURE_RANG_150              Ranging from 150
  '''
  urm09.set_mode_range(urm09._MEASURE_MODE_PASSIVE, urm09._MEASURE_RANG_500)

def loop():
  #Write command register and send ranging command
  urm09.measurement_start()
  time.sleep(0.1)
  #Read distance register
  dist = urm09.get_distance()
  #Read temperature register
  temp = urm09.get_temperature()
  print("Distance is %d cm         " %dist)
  print("Temperature is %.2f .c    " %temp)
  time.sleep(0.1)

if __name__ == "__main__":
  setup()
  while True:
    loop()