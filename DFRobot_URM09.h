/*

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

 */
#ifndef __DFRobot_URM09_H__
#define __DFRobot_URM09_H__

#include <Wire.h>
#include <Arduino.h>

#define    MEASURE_MODE_AUTOMATIC  (0x80)           // automatic mode
#define    MEASURE_MODE_PASSIVE    (0x00)           // passive mode

#define    CMD_DISTANCE_MEASURE    (0x01)           // passive mode configure registers

#define    MEASURE_RANG_500        (0x20)           // Ranging from 500 
#define    MEASURE_RANG_300        (0x10)           // Ranging from 300 
#define    MEASURE_RANG_150        (0x00)           // Ranging from 100 


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
  
  DFRobot_URM09();
  ~DFRobot_URM09();
  bool    begin(uint8_t addr0 = 0x11);
  void    SetModeRange(uint8_t Range ,uint8_t SetMode);
  void    SetMeasurement();
  int16_t i2cReadTemperature();
  int16_t i2cReadDistance();
  int16_t GetI2cDeviceAddress();
  uint8_t ReadDeviceAddress();
  void    ModifyDeviceAddress(uint8_t Address); 
  uint8_t txbuf[10] = {0};
  
private:
  void    i2cWriteTemDistance(uint8_t Reg, uint8_t *pdata, uint8_t datalen);
  uint8_t _addr;
};

#endif