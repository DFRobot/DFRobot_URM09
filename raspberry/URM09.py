# Connect URM09 and raspberry pi via I2C.
#
# Urm09 is an ultrasonic ranging equipment, which has two ultrasonic probes, one receiving and one sending. 
# The equipment can measure the temperature of the module. 
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


import time
import smbus

class DFRobot_URM09:

  MEASURE_MODE_AUTOMATIC = 0x80          # automatic mode
  MEASURE_MODE_PASSIVE   = 0x00          # passive mode
  
  CMD_DISTANCE_MEASURE   = 0x01          # passive mode configure registers
  
  MEASURE_RANG_500       = 0x20          # Ranging from 500
  MEASURE_RANG_300       = 0x10          # Ranging from 300 
  MEASURE_RANG_150       = 0x00          # Ranging from 100
  
  
  SLAVEADDR_INDEX = 0
  PID_INDEX       = 1
  VERSION_INDEX   = 2
  DIST_H_INDEX    = 3
  DIST_L_INDEX    = 4
  
  TEMP_H_INDEX    = 5
  TEMP_L_INDEX    = 6

  CFG_INDEX       = 7
  CMD_INDEX       = 8
  REG_NUM         = 9

  
  def __init__(self):
    # The i2c default device number is 0x11 
    self.__private_addr  = 0x11
    self.txbuf = [0]
    self.i2c   = smbus.SMBus(1)
  # Set i2c device number 
  def begin(self, calib):
    self.__private_addr = calib

  # Set the automatic mode or the passive mode and the measurement distance
  def SetModeRange(self ,Range ,SetMode):
    self.txbuf = [Range | SetMode]
    self.URM09_set_regs(self.CFG_INDEX ,self.txbuf)

  # Write command registers and send ranging commands in passive mode
  def SetMeasurement(self ,Measurement):
    self.txbuf = [Measurement]
    self.URM09_set_regs(self.CMD_INDEX ,self.txbuf)

  # Read the temperature data of the register
  def i2cReadTemperature(self):
    rslt = self.URM09_get_regs(self.TEMP_H_INDEX ,2)
    return (float)((rslt[0] << 8) + rslt[1])

  # Read the distance data of the register
  def i2cReadDistance(self):
    rslt = self.URM09_get_regs(self.DIST_H_INDEX ,2)
    if ((rslt[0] << 8) + rslt[1]) < 32768:
      return ((rslt[0] << 8) + rslt[1])
    else : 
      return (((rslt[0] << 8) + rslt[1]) - 65536)

  # Modify i2c device number
  def ModifyDeviceNumber(self ,Address):
    self.txbuf = [Address]
    self.URM09_set_regs(self.SLAVEADDR_INDEX ,self.txbuf)

  # read i2c device number
  def ReadDeviceNumber(self):
    rslt = self.URM09_get_regs(self.SLAVEADDR_INDEX ,1)
    return rslt[0]

  # Write data to the i2c register
  def URM09_get_regs(self ,reg ,len):
    rslt = self.i2c.read_i2c_block_data(self.__private_addr,reg,len)
    return rslt
    
  # Write data to the i2c register  
  def URM09_set_regs(self ,reg ,data):
    self.i2c.write_i2c_block_data(self.__private_addr,reg,data)

