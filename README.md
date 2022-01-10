# DFRobot_URM09
- [中文版](./README_CN.md)

This is an ultrasonic distance sensor module with open dual probe. It adopts I2C communication and standard interface of Gravity PH2.0-4P vertical patch socket. The module is compatible with controllers with 3.3V or 5V logical level, such as Arduino and Raspberry Pi. The ultrasonic sensor comes with built-in temperature compensation, providing effective ranging within 2cm to 500cm. It offers resolution of 1cm and accuracy of ±1%. There are three measurement ranges designed for programs to select: 150cm, 300cm, 500cm. Please note that setting shorter range will cause shorter ranging cycle and lower sensitivity. You may need to set it according to the actual use.

This module can be widely applied to outdoor environment, not least with rapid changes of temperature difference. It is definitely a prime select when it comes to projects like robot auto collision avoidance walk, car reversing alarm, doorbell, guard alert, subway safety line prompt, and one meter line prompt in bank and front of ATM machine. <br>
This ranging module, with small size, provides strong environment applicability, high accuracy and wide measurement range, plug and play, easy to use.

![效果图](resources/images/SEN0304_WIKI_Cover.jpg)


## Product Link（https://www.dfrobot.com/product-1832.html）

    SKU：SEN0304

## Table of Contents

* [Summary](#Summary)
* [Installation](#Installation)
* [Methods](#Methods)
* [Compatibility](#Compatibility)
* [History](#History)
* [Credits](#Credits)

## Summary

Effective ranging within 2cm to 500cm, resolution of 1cm and accuracy of ±1%.

There are three measurement ranges: 150cm, 300cm, 500cm. Two measurement modes: active or passive(select by program).

Revisable I2C device address, avoiding multiple devices address conflicts. 

## Installation
There are two methods for using this library:
1. Open Arduino IDE, search for "DFRobot_MGC3130" on the status bar in Tools ->Manager Libraries and install the library.
2. Download the library file before use, paste it into \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  /**
   * @fn begin
   * @brief Init i2c
   * @param address I2C device number (1-127), default to 0x11 when no device number is uploaded
   * @return Return bool type, indicating init status
   * @retval true Init succeed
   * @retval false Init failed
   */
  bool begin(uint8_t address = 0x11);

  /**
   * @fn setModeRange
   * @brief Set mode and measure distance 
   * @param range is measured range
   * @n     MEASURE_RANG_500    Ranging from 500 
   * @n     MEASURE_RANG_300    Ranging from 300 
   * @n     MEASURE_RANG_150    Ranging from 150 
   * @param mode is measurement mode, automatic measurement and passive measurement. 
   * @n     MEASURE_MODE_AUTOMATIC    automatic mode
   * @n     MEASURE_MODE_PASSIVE      passive mode
   * @return None
   */
  void setModeRange(uint8_t range, uint8_t mode);

  /**
   * @fn measurement
   * @brief Measure distance, send measurement command in passive mode.
   * @return None
   */
  void measurement(void);

  /**
   * @fn getTemperature
   * @brief Get temperature value
   * @return Temperature value, unit (℃)
   */
  float getTemperature(void);

  /**
   * @fn getDistance
   * @brief Read distance
   * @return Distance value, unit (cm)
   * @n The increase is 10 times as the actual temperature
   * @n For example: if the read value is 0x00fe, the actual temperature will be 0x00fe / 10 = 25.4
   * @return None
   */
  int16_t getDistance(void);

  /**
   * @fn scanDevice
   * @brief Scan i2c device
   * @return Scanning status
   * @retval -1 Device is not scanned
   * @retval other iic address
   */
  int16_t scanDevice(void);
  
  /**
   * @fn getI2CAddress
   * @brief Get i2c device address number
   * @return i2c Device address number
   */
  uint8_t getI2CAddress(void);

  /**
   * @fn modifyI2CAddress
   * @brief Change i2c device address
   * @param address i2c device address number (1-127)
   * @return None
   */
  void modifyI2CAddress(uint8_t address);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | :----:
Arduino Uno        |      √       |              |             |
Arduino MEGA2560   |      √       |              |             |
Arduino Leonardo   |      √       |              |             |
FireBeetle-ESP32   |      √       |              |             |
Micro:bit          |              |              |      √      |


## History

- 2019/06/25 - V1.0.0 Version
- 2020/05/30 - V1.1.0 Version
- 2021/09/30 - V1.2.0 Version

## Credits

Written by ZhixinLiu(zhixin.liu@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
