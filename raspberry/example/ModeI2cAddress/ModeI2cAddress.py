# -*- coding:utf-8 -*-

'''
  # ModeI2cAddress.py
  #
  # Connect board with raspberryPi.
  # Make board power and URM09 connection correct.
  # Run this demo.
  #
  # Set the i2c communication device number.
  # Read the current i2c device number 
  # set the new device number of i2c 
  # Read the device number 
  
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

''' Create a URM09 object to communicate with I2C  '''
URM09 = URM09.DFRobot_URM09()

''' Set the i2c device number '''
URM09.begin(0x11)

Address = URM09.ReadDeviceNumber()
print("The old device address for i2c is at %#x" %Address)
time.sleep(0.1)

''' Change the device number of i2c, value range 1 to 127 '''
URM09.ModifyDeviceNumber(0x11)

time.sleep(0.1)
Address = URM09.ReadDeviceNumber()
print("The new device address for i2c is at %#x" %Address)
print("The new address needs to be powered off and reconnected to take effect")
