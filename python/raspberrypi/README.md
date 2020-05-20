# DFRobot URM09 Ultrasonic Ranging 

This RaspberryPi URM09 board can communicate with RaspberryPi via IIC. <br>
URM09 can measure data from 2 to 500 cm, and displays -1 when no data is detected.<br>
URM09 can measure the temperature of the module. <br>
Application: RaspberryPi smart car... <br>


## DFRobot URM09 Library for RaspberryPi

Provide the Raspberry Pi library for the URM09 module.

## Table of Contents

* [Summary](#summary)
* [Feature](#feature)
* [Installation](#installation)
* [Methods](#methods)
* [Credits](#credits)

## Summary

URM09 module.

## Feature

1. The module has two ultrasonic rangings, one for transmission and the other for reception. <br>
2. Can measure the temperature of the module. <br>
3. The measuring distance can be configured to be 150cm, 300cm, 500cm. The smaller the distance, the higher the precision. <br>
4. Can be configured for both active and passive measurements. <br>

## Installation

This Sensor should work with DFRobot_URM09 on RaspberryPi. <br>
Run the program:

```
$> python AutoMeasure.py
$> python ModeI2cAddress.py
$> python PassiveMeasure.py
```

## Methods

```py

class DFRobot_URM09:

  ''' Configuration mode and parameters '''
  _MEASURE_MODE_AUTOMATIC = 0x80          # automatic mode
  _MEASURE_MODE_PASSIVE   = 0x00          # passive mode
  
  _CMD_DISTANCE_MEASURE   = 0x01          # passive mode configure registers
  
  _MEASURE_RANG_500       = 0x20          # Ranging from 500
  _MEASURE_RANG_300       = 0x10          # Ranging from 300 
  _MEASURE_RANG_150       = 0x00          # Ranging from 150
  
  ''' register configuration '''
  SLAVEADDR_INDEX = 0
  PID_INDEX       = 1
  VERSION_INDEX   = 2
  DIST_H_INDEX    = 3                     #Distance register high 8 bits
  DIST_L_INDEX    = 4                     #Distance register low 8 bits
  
  TEMP_H_INDEX    = 5                     #Temperature register high 8 bits
  TEMP_L_INDEX    = 6                     #Temperature register low 8 bits

  CFG_INDEX       = 7
  CMD_INDEX       = 8
  REG_NUM         = 9
  
  ''' Conversion data '''
  txbuf      = [0]                        #Temporary data
  
  def set_mode_range(self ,Range ,SetMode):
    '''
      @brief    Set dc motor encoder reduction ratio
      @param Range: Measured distance
            # _MEASURE_RANG_500              // Ranging from 500 
            # _MEASURE_RANG_300              // Ranging from 300 
            # _MEASURE_RANG_150              // Ranging from 150
      @param SetMode: Set mode
            # _MEASURE_MODE_AUTOMATIC        // automatic mode
            # _MEASURE_MODE_PASSIVE          // passive mode
    '''

  def measurement_start(self):
    '''
      @brief    Passive mode ranging command
    '''

  def read_temperature(self):
    '''
      @brief    read Temperature
      @return   Temperature
    '''

  def read_distance(self):
      '''
      @brief    read Distance
      @return   Distance
    '''

  def modify_device_number(self ,Address):
    '''
      @brief    Modify i2c device number
      @param Address: i2c device number 1-127
    '''

  def read_device_number(self):
    '''
      @brief    read i2c device number
      @return   i2c device number
    '''
```
## History

- June 25, 2019 - Version 1.0 released.
-  May 20, 2020 - Version 1.1 released.

## Credits
Written by ZhixinLiu(zhixin.liu@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))