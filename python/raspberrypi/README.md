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
$> python auto_measure.py
$> python mode_i2c_address.py
$> python passive_measure.py
```

## Methods

```py

  def set_mode_range(self ,Range ,SetMode):
    '''
      @brief    Set dc motor encoder reduction ratio
      @param Range: Measured distance
      @n            _MEASURE_RANG_500             # Ranging from 500 
      @n            _MEASURE_RANG_300             # Ranging from 300 
      @n            _MEASURE_RANG_150             # Ranging from 150
      @param SetMode: Set mode
      @n            _MEASURE_MODE_AUTOMATIC       # automatic mode
      @n            _MEASURE_MODE_PASSIVE         # passive mode
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