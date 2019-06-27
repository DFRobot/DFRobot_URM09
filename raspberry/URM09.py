# -*- coding:utf-8 -*-

'''
 MIT License

 Copyright (C) <2019> <@DFRobot Frank>

  Permission is hereby granted, free of charge, to any person obtaining a copy of this
  software and associated documentation files (the "Software"), to deal in the Software
  without restriction, including without limitation the rights to use, copy, modify,
  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so.

  The above copyright notice and this permission notice shall be included in all copies or
  substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'''

import time
import smbus

class DFRobot_URM09:


  ''' Configuration mode and parameters '''
  _MEASURE_MODE_AUTOMATIC = 0x80          # automatic mode
  _MEASURE_MODE_PASSIVE   = 0x00          # passive mode
  
  _CMD_DISTANCE_MEASURE   = 0x01          # passive mode configure registers
  
  _MEASURE_RANG_500       = 0x20          # Ranging from 500
  _MEASURE_RANG_300       = 0x10          # Ranging from 300 
  _MEASURE_RANG_150       = 0x00          # Ranging from 100
  
  ''' Enum register configuration '''
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
  
  def __init__(self):
    ''' The i2c default device number is 0x11 '''
    self.__addr  = 0x11
    self.i2c     = smbus.SMBus(1)

  ''' Set i2c device number '''
  def begin(self, calib):
    self.__addr = calib

  ''' Set the automatic mode or the passive mode and the measurement distance '''
  def SetModeRange(self ,Range ,SetMode):
    self.txbuf = [Range | SetMode]
    self.URM09_set_regs(self.CFG_INDEX ,self.txbuf)

  ''' Write command registers and send ranging commands in passive mode '''
  def SetMeasurement(self):
    self.txbuf = [self._CMD_DISTANCE_MEASURE]
    self.URM09_set_regs(self.CMD_INDEX ,self.txbuf)

  ''' Read the temperature data of the register '''
  def i2cReadTemperature(self):
    rslt = self.URM09_get_regs(self.TEMP_H_INDEX ,2)
    return (float)((rslt[0] << 8) + rslt[1])

  ''' Read the distance data of the register '''
  def i2cReadDistance(self):
    rslt = self.URM09_get_regs(self.DIST_H_INDEX ,2)
    if ((rslt[0] << 8) + rslt[1]) < 32768:
      return ((rslt[0] << 8) + rslt[1])
    else : 
      return (((rslt[0] << 8) + rslt[1]) - 65536)

  ''' Modify i2c device number '''
  def ModifyDeviceNumber(self ,Address):
    self.txbuf = [Address]
    self.URM09_set_regs(self.SLAVEADDR_INDEX ,self.txbuf)

  ''' read i2c device number '''
  def ReadDeviceNumber(self):
    rslt = self.URM09_get_regs(self.SLAVEADDR_INDEX ,1)
    return rslt[0]

  ''' Write data to the i2c register '''
  def URM09_get_regs(self ,reg ,len):
    rslt = self.i2c.read_i2c_block_data(self.__addr,reg,len)
    return rslt
    
  ''' Write data to the i2c register '''
  def URM09_set_regs(self ,reg ,data):
    self.i2c.write_i2c_block_data(self.__addr,reg,data)

