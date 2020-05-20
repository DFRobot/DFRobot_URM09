#ifndef __DFRobot_URM09_H__
#define __DFRobot_URM09_H__

#include <Wire.h>
#include <Arduino.h>

#define    MEASURE_MODE_AUTOMATIC  0x80           // automatic mode
#define    MEASURE_MODE_PASSIVE    0x00           // passive mode

#define    CMD_DISTANCE_MEASURE    0x01           // passive mode configure registers

#define    MEASURE_RANG_500        0x20           // Ranging from 500 
#define    MEASURE_RANG_300        0x10           // Ranging from 300 
#define    MEASURE_RANG_150        0x00           // Ranging from 100 


class DFRobot_URM09{  
public:
  /*
   * @brief Enum register configuration
   */
  typedef enum{
    eSLAVEADDR_INDEX = 0,
    ePID_INDEX,
    eVERSION_INDEX,
    eDIST_H_INDEX,         //High distance eight digits 
    eDIST_L_INDEX,         //Low  distance eight digits 
    eTEMP_H_INDEX,         //High temperature eight digits 
    eTEMP_L_INDEX,         //Low  temperature eight digits 
    eCFG_INDEX,
    eCMD_INDEX,
    eREG_NUM
  }eRegister_t;
  
  DFRobot_URM09();
  ~DFRobot_URM09();
  bool    begin(uint8_t addr0 = 0x11);
  void    SetModeRange(uint8_t Range ,uint8_t SetMode);
  void    SetMeasurement();
  float   i2cReadTemperature();
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