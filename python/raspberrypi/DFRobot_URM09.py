# -*- coding: utf-8 -*
import serial
import time
import smbus
                

class DFRobot_URM09(object):

  ''' Configuration mode and parameters '''
  _MEASURE_MODE_AUTOMATIC = 0x80          # automatic mode
  _MEASURE_MODE_PASSIVE   = 0x00          # passive mode
  
  _CMD_DISTANCE_MEASURE   = 0x01          # passive mode configure registers
  
  _MEASURE_RANG_500       = 0x20          # Ranging from 500
  _MEASURE_RANG_300       = 0x10          # Ranging from 300 
  _MEASURE_RANG_150       = 0x00          # Ranging from 100
  
  ''' register configuration '''
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
  
  ''' Conversion data '''
  txbuf      = [0]
  
  def __init__(self ,bus):
    self.i2cbus = smbus.SMBus(bus)

  ''' Set the automatic mode or the passive mode and the measurement distance '''
  def set_mode_range(self ,Range ,SetMode):
    self.txbuf = [Range | SetMode]
    self.write_reg(self.CFG_INDEX ,self.txbuf)

  ''' Write command registers and send ranging commands in passive mode '''
  def measurement_start(self):
    self.txbuf = [self._CMD_DISTANCE_MEASURE]
    self.write_reg(self.CMD_INDEX ,self.txbuf)

  ''' Read the temperature data of the register '''
  def read_temperature(self):
    rslt = self.read_reg(self.TEMP_H_INDEX ,2)
    return (float)(((rslt[0] << 8) + rslt[1]) / 10)

  ''' Read the distance data of the register '''
  def read_distance(self):
    rslt = self.read_reg(self.DIST_H_INDEX ,2)
    if ((rslt[0] << 8) + rslt[1]) < 32768:
      return ((rslt[0] << 8) + rslt[1])
    else : 
      return (((rslt[0] << 8) + rslt[1]) - 65536)

  ''' Modify i2c device number '''
  def modify_device_number(self ,Address):
    self.txbuf = [Address]
    self.write_reg(self.SLAVEADDR_INDEX ,self.txbuf)

  ''' read i2c device number '''
  def read_device_number(self):
    rslt = self.read_reg(self.SLAVEADDR_INDEX ,1)
    return rslt[0]

class DFRobot_URM09_IIC(DFRobot_URM09): 
  def __init__(self ,bus ,addr):
    self.__addr = addr;
    super(DFRobot_URM09_IIC, self).__init__(bus)
    
  def write_reg(self, reg, data):
    self.i2cbus.write_i2c_block_data(self.__addr ,reg ,data)

  def read_reg(self, reg ,len):
    rslt = self.i2cbus.read_i2c_block_data(self.__addr ,reg ,len)
    return rslt