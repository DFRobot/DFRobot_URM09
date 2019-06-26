# URM09 Library for Arduino
This is a Library for URM09, the function is to read temperature and distance.

## Table of Contents

* [Summary](#summary)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


<snippet>
<content>

## Summary
* This is an open dual-probe ultrasonic ranging module.
* The library supports the I2C communication.
* This library provides examples of automatic and passive distance measurements using ultrasonic sensors. 
* The module is provided with temperature compensation, the effective ranging range of the flat wall surface is 2 to 500 cm.
* The resolution is 1 cm, and the error is about 1%.
* The design of three ranging ranges of 150cm, 300cm and 500cm can be used for program selection and switching.
* Shorter range setting will result in shorter ranging period and lower ranging sensitivity.
* This new barometric pressure sensor exhibits an attractive price-performance ratio coupled with low power consumption.

## Methods
* First of all, we need to get the device number of the urm09 device, which can be obtained using geti2cdeviceaddress.ino. 
* The default device number of the urm09 is 0x11. 

* You can use modifydeviceaddress.ino to configure the device number from 1~127, but first we need to know the device number of urm09. 
* The passive mode needs to be set to passive mode and the configuration register can obtain the distance value.
* Automatic mode only needs to be set to active mode to get the distance value of the register.



### Arduino
```C++
#include <DFRobot_URM09.h>


/*
 * @brief initialization parameters for i2c 
 * @return flag
 */
int16_t begin();


/*
 * @brief initialization parameters for i2c
 *
 * @param addr0 is I2c device number 
 *
 * @return flag
 */
int16_t begin(uint8_t addr0);
  
  
/*
 * @brief Set mode and measure distance 
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
void SetModeRange(int Range ,int SetMode);


/*
 * @brief Passive measurement mode setting measurement register 
 *
 * @param Measurement is Write an order.
 */
void SetMeasurement(int Measurement);
  
  
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
 * @return i2c device number or error flag.
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
void    ModifyDeviceAddress(uint8_t Address); 



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


## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32   |      √       |             |            | 
RaspberrayPi       |      √       |             |            | Only support python3
Arduino            |      √       |             |            | 

## History

- data 2019-6-26
- version V0.1


## Credits

- author [liu]
