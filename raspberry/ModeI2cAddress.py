# Connect URM09 and raspberry pi via I2C.
#
# This example can modify the device number of i2c with a value of 1-127 
#
# Warning:
#   This demo only supports python3.
#   Run this demo: python3 I2C Count Distance
#
# connect:
#   raspberry       URM09
#   3.3v(1)         VCC
#   GND(9)          GND
#   SCL(5)          SCL
#   SDA(3)          SDA

import URM09
import time

# Create a URM09 object to communicate with I2C.
URM09 = URM09.DFRobot_URM09()
# Set the i2c device number 
URM09.begin(0x11)

Address = URM09.ReadDeviceNumber()
print("The old device address for i2c is at %#x" %Address)
time.sleep(0.1)
# Change the device number of i2c, value range 1 to 127 
URM09.ModifyDeviceNumber(0x15)

time.sleep(0.1)
Address = URM09.ReadDeviceNumber()
print("The new device address for i2c is at %#x" %Address)
print("The new address needs to be powered off and reconnected to take effect")
