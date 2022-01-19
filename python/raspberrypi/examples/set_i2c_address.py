# -*- coding:utf-8 -*-
'''!
  @file set_i2c_address.py
  @brief Change the iic device address
  @n First print the current iic device address, after printing the changed device address
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
  address = urm09.get_device_number()
  print("The old device address for i2c is at %#x" %address)
  time.sleep(0.1)
  #Change the device number of i2c, value range 1 to 127
  urm09.modify_device_number(0x11)
  time.sleep(0.1)
  address = urm09.get_device_number()
  print("The new device address for i2c is at %#x" %address)
  print("The new address needs to be powered off and reconnected to take effect")

if __name__ == "__main__":
  setup()