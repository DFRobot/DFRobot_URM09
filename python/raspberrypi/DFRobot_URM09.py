# -*- coding: utf-8 -*
'''!
  @file DFRobot_URM09.py
  @brief Define the basic structure of DFRobot_URM09 class, the implementation of basic method
  @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license The MIT License (MIT)
  @author ZhixinLiu(zhixin.liu@dfrobot.com)
  @version V1.1
  @date 2021-9-30
  @url https://github.com/DFRobot/DFRobot_URM09
'''
import serial
import time
import smbus

class DFRobot_URM09(object):

  ## automatic mode
  _MEASURE_MODE_AUTOMATIC = 0x80
  ## passive mode
  _MEASURE_MODE_PASSIVE   = 0x00
  ## passive mode configure registers
  _CMD_DISTANCE_MEASURE   = 0x01
  ## Ranging from 500
  _MEASURE_RANG_500       = 0x20
  ## Ranging from 300 
  _MEASURE_RANG_300       = 0x10
  ## Ranging from 150
  _MEASURE_RANG_150       = 0x00
  
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
  txbuf      = [0]
  def __init__(self, bus):
    self.i2cbus = smbus.SMBus(bus)

  def set_mode_range(self, range, mode):
    '''!
      @brief    set dc motor encoder reduction ratio
      @param range: Measured distance
      @n            _MEASURE_RANG_500             #Ranging from 500
      @n            _MEASURE_RANG_300             #Ranging from 300
      @n            _MEASURE_RANG_150             #Ranging from 150
      @param mode: Set mode
      @n            _MEASURE_MODE_AUTOMATIC       #automatic mode
      @n            _MEASURE_MODE_PASSIVE         #passive mode
    '''
    self.txbuf = [range | mode]
    self.write_reg(self.CFG_INDEX, self.txbuf)

  def measurement_start(self):
    '''!
      @brief    Passive mode ranging command
    '''
    self.txbuf = [self._CMD_DISTANCE_MEASURE]
    self.write_reg(self.CMD_INDEX, self.txbuf)

  def get_temperature(self):
    '''!
      @brief    get Temperature
      @return   Temperature
    '''
    rslt = self.read_reg(self.TEMP_H_INDEX, 2)
    if rslt == -1:
      return 25.0
    return (float)(((rslt[0] << 8) + rslt[1]) / 10)

  def get_distance(self):
    '''!
      @brief    get distance
      @return   Distance
    '''
    temp = 0.0
    rslt = self.read_reg(self.DIST_H_INDEX, 2)
    if rslt == -1:
      return -1
    if ((rslt[0] << 8) + rslt[1]) < 32768:
      return ((rslt[0] << 8) + rslt[1])
    else: 
      return (((rslt[0] << 8) + rslt[1]) - 65536)

  def modify_device_number(self, Address):
    '''!
      @brief    Modify i2c device number
      @param Address: i2c device number 1-127
    '''
    self.txbuf = [Address]
    self.write_reg(self.SLAVEADDR_INDEX, self.txbuf)

  def get_device_number(self):
    '''!
      @brief    read i2c device number
      @return   i2c device number
    '''
    rslt = self.read_reg(self.SLAVEADDR_INDEX, 1)
    return rslt[0]

class DFRobot_URM09_IIC(DFRobot_URM09): 
  def __init__(self, bus, addr):
    self.__addr = addr
    super(DFRobot_URM09_IIC, self).__init__(bus)

  def write_reg(self, reg, data):
    while 1:
      try:
        self.i2cbus.write_i2c_block_data(self.__addr, reg, data)
        return
      except:
        print("please check connect!")
        time.sleep(1)
    
  def read_reg(self, reg, len):
    try:
      rslt = self.i2cbus.read_i2c_block_data(self.__addr, reg, len)
    except:
      rslt = -1
    return rslt