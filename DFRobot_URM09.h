/*!
 * @file DFRobot_URM09.h
 * @brief DFRobot's DFRobot_URM09
 * @n DFRobot's Temperature, distance 
 * 
 * @copyright     [DFRobot](http://www.dfrobot.com.cn)
 * @copyright     GNU Lesser General Public License
 * 
 * @author        LIU
 * @version       V1.0
 * @date          2019-6-21
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

#define    URM09_NO                (-1)
#define    URM09_OK                ( 0)
#endif

enum DFRobot_enum {
  SLAVEADDR_INDEX = 0,
  PID_INDEX,
  VERSION_INDEX ,

  DIST_H_INDEX,
  DIST_L_INDEX,
  
  TEMP_H_INDEX,
  TEMP_L_INDEX,

  CFG_INDEX,
  CMD_INDEX,
  REG_NUM
};

class DFRobot_URM09{  
public:
  uint8_t begin();
  uint8_t begin(uint8_t addr0);
  void    SetModeRange(uint8_t Range ,uint8_t SetMode);
  void    SetMeasurement(uint8_t Measurement);
  int16_t i2cReadTemperature();
  int16_t i2cReadDistance();
  uint8_t GetI2cDeviceAddress();
  uint8_t ReadDeviceAddress();
  void    ModifyDeviceAddress(uint8_t Address); 
private:
  void i2cWriteTemDistance(uint8_t Reg , uint8_t *pdata, uint8_t datalen );
  uint8_t addr;
  uint8_t txbuf[10] = {0};
  };
