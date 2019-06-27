# URM09
DFRobot's Distance, Temperature

## DFRobot_URM09 Library for Arduino
---------------------------------------------------------
Provides an Arduino library for reading and interpreting Bosch URM09 data over I2C. <br>
Used to read the current distance and the temperature of the module 


## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

<snippet>
<content>

## Installation

To use this library download the zip file, uncompress it to a folder named DFRobot_URM09. 
Download the zip file first to use this library and uncompress it to a folder named DFRobot_URM09. 

## Methods

```C++
class DFRobot_URM09{  
public:
  /*
   * @brief Enum register configuration
   */
  typedef enum{
    SLAVEADDR_INDEX = 0,
    PID_INDEX,
    VERSION_INDEX,
    DIST_H_INDEX,         //High distance eight digits 
    DIST_L_INDEX,         //Low  distance eight digits 
    TEMP_H_INDEX,         //High temperature eight digits 
    TEMP_L_INDEX,         //Low  temperature eight digits 
    CFG_INDEX,
    CMD_INDEX,
    REG_NUM
  }eRegister_t;

 /*
  * @brief initialization parameters for i2c
  *
  * @param addr0 is I2c device number 
  *
  * @return true and false
  */
   bool begin(uint8_t addr0 = 0x11);

 /*
  * @brief Set mode and measure distance 
  *
  * @param Range is measured range
  *        #define    MEASURE_RANG_500    // Ranging from 500 
  *        #define    MEASURE_RANG_300    // Ranging from 300 
  *        #define    MEASURE_RANG_150    // Ranging from 100 
  *
  * @param SetMode is measurement pattern
           Set measurement mode, automatic measurement and passive measurement. 
  *        #define    MEASURE_MODE_AUTOMATIC       // automatic mode
  *        #define    MEASURE_MODE_PASSIVE         // passive mode
  */
   void SetModeRange(uint8_t Range ,uint8_t SetMode);

 /*
  * @brief Passive measurement mode setting measurement register 
  */
   void SetMeasurement();

 /*
  * @brief read temperature.
  *
  * @return Temperature value.
  */
   int16_t i2cReadTemperature();

 /*
  * @brief read distance.
  *
  * @return distance value.
  *         The value of an increase of 10 times the actual temperature. 
  *         Example: if the readout value is 0x00fe, the actual temperature is 0x00fe / 10 = 25.4 
  */
   int16_t i2cReadDistance();

 /*
  * @brief Get i2c device number.
  *
  * @return i2c device number or -1.
  */
   int16_t GetI2cDeviceAddress();

 /*
  * @brief read i2c device number.
  *
  * @return i2c device number.
  */
   uint8_t ReadDeviceAddress();

 /*
  * @brief Modify the i2c device number.
  *
  * @param i2c device number.
  */
   void ModifyDeviceAddress(uint8_t Address); 

};

```

### raspberry 
```Python
import URM09

/*
 * @brief Set i2c device number 
 *
 * @param I2c device number
 */
  def begin(self, calib):

/*
 * @brief Set the automatic mode or the passive mode and the measurement distance
 *
 * @param Range is measured range
 *        #define    MEASURE_RANG_500  (0x20)     // Ranging from 500 
 *        #define    MEASURE_RANG_300  (0x10)     // Ranging from 300 
 *        #define    MEASURE_RANG_150  (0x00)     // Ranging from 100 
 *
 * @param SetMode is measurement pattern
          Set measurement mode, automatic measurement and passive measurement. 
 *        #define    MEASURE_MODE_AUTOMATIC  (0x80)           // automatic mode
 *        #define    MEASURE_MODE_PASSIVE    (0x00)           // passive mode
 */
  def SetModeRange(self ,Range ,SetMode):

/*
 * @brief Write command registers and send ranging commands in passive mode 
 *
 * @param Measurement is Write an order.
 */
  def SetMeasurement(self ,Measurement):

/*
 * @brief Read the temperature data of the register
 *
 * @return Temperature value. 
 *         The value of an increase of 10 times the actual temperature. 
 *         Example: if the readout value is 0x00fe, the actual temperature is 0x00fe / 10 = 25.4 
 */
  def i2cReadTemperature(self):

/*
 * @brief Read the distance data of the register
 *
 * @return Distance value. 
 */
  def i2cReadDistance(self):

/*
 * @brief Modify the i2c device number.
 *
 * @param i2c device number.
 */
  def ModifyDeviceNumber(self ,Address):


/*
 * @brief read i2c device number.
 *
 * @return i2c device number.
 */
  def ReadDeviceNumber(self):
```

## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32   |      √       |              |             | 
RaspberrayPi       |      √       |              |             | Only support python3
Arduino uno        |      √       |              |             | 

## History

- June 25, 2019 - Version 0.1 released.


## Credits

Written by Frank(jiehan.guo@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))