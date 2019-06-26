# Connect URM09 and raspberry pi via I2C.
#
# This example can read the temperature of the module.
# This example demonstrates passive measurement data
# Send a command to the configuration register, and then read the data 
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
time.sleep(0.1)
# The module is configured in passive mode and the ranging range is set to 500cm
URM09.SetModeRange(URM09.MEASURE_MODE_PASSIVE ,URM09.MEASURE_RANG_500)

while(1):
  # Write command register and send ranging command 
  URM09.SetMeasurement(URM09.CMD_DISTANCE_MEASURE)
  time.sleep(0.1)
  # Read distance register
  dist = URM09.i2cReadDistance()
  # Read temperature register 
  temp = URM09.i2cReadTemperature()
  
  print("Temperature is %.2f .c " %(temp / 10))
  print("Distance is %d cm " %dist)
  print("success")
  time.sleep(0.1)

