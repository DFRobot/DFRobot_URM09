/*!
 * @file DFRobot_URM09.cpp
 * @brief DFRobot's DFRobot_URM09
 * @n DFRobot's Temperature, Pressure and Approx altitude
 *    Supports the I2C communication with Arduino.
 *
 * @copyright      [DFRobot](http://www.dfrobot.com.cn)
 * @copyright      GNU Lesser General Public License
 *
 * @author         LIU
 * @version        V1.0
 * @date           2019-6-21
 */
#include "DFRobot_URM09.h"
#include <Arduino.h>
#include <Wire.h>

/* join i2c bus (address optional for master) */
uint8_t DFRobot_URM09::begin()
{
  this->addr = 0x11;               // Default host address 
  Wire.begin();                    // connecting the i2c bus 
  Wire.beginTransmission(addr);
  
  if(Wire.endTransmission() == 0)
    return URM09_OK;
  return URM09_NO;
}


uint8_t DFRobot_URM09::begin(uint8_t addr0)
{
  this->addr = addr0;              // Set the host address 
  Wire.begin();                    // connecting the i2c bus 
  Wire.beginTransmission(addr);
  if(Wire.endTransmission() == 0)
    return URM09_OK;
  return URM09_NO;
}


/* Set the automatic mode or the passive mode and the measurement distance */
void DFRobot_URM09::SetModeRange(uint8_t Range ,uint8_t SetMode)
{  
  txbuf[0] = (uint8_t)(Range | SetMode);   // Mode and range write to configuration register. 
  i2cWriteTemDistance(CFG_INDEX , &txbuf[0], 1 );
}

/* Write command registers and send ranging commands in passive mode */
void DFRobot_URM09::SetMeasurement(uint8_t Measurement)
{ 
  txbuf[0] = Measurement;
  i2cWriteTemDistance(CMD_INDEX , &txbuf[0],1 );
}

/* Read the temperature data of the register */
int16_t DFRobot_URM09::i2cReadTemperature()
{
  uint8_t i = 0;
  uint8_t rxbuf[10] = {0};
  Wire.beginTransmission(addr);     // transmit to device Address
  Wire.write(TEMP_H_INDEX);         // sends one byte
  Wire.endTransmission();           // stop transmitting
  Wire.requestFrom(addr, (uint8_t)2);
  while (Wire.available())          // slave may send less than requested
    rxbuf[i++] = Wire.read();
  
  return ((int16_t)rxbuf[0] << 8) + rxbuf[1];
}
/* Read the distance data of the register  */
int16_t DFRobot_URM09::i2cReadDistance()
{
  uint8_t i = 0;
  uint8_t rxbuf[10] = {0};
    
  Wire.beginTransmission(addr);     // transmit to device Address
  Wire.write(DIST_H_INDEX);         // sends one byte
  Wire.endTransmission();           // stop transmitting
  Wire.requestFrom(addr, (uint8_t)2);
  while (Wire.available())          // slave may send less than requested
    rxbuf[i++] = Wire.read();
  
  return ((int16_t)rxbuf[0] << 8) + rxbuf[1];
}

/* Write data to the i2c register  */
void DFRobot_URM09::i2cWriteTemDistance(uint8_t Reg , uint8_t *pdata, uint8_t datalen )
{
  Wire.beginTransmission(addr);        // transmit to device #8
  Wire.write(Reg);                     // sends one byte
  for (uint8_t i = 0; i < datalen; i++) 
    Wire.write(pdata[i]);
  Wire.endTransmission();              // stop transmitting
}


/* Get the i2c device address */
uint8_t DFRobot_URM09::GetI2cDeviceAddress()
{
  Wire.begin();                    // connecting the i2c bus 
  uint8_t error ,address;
  // the Write.endTransmisstion to see if a device did acknowledge to the address.
  for (address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
      return address;
  }
  return URM09_NO;
}

/* Modify i2c device number  */
void DFRobot_URM09::ModifyDeviceAddress(uint8_t Address)
{
  txbuf[0] = Address;
  // Write the new address xxxx to the address register. 
  i2cWriteTemDistance(SLAVEADDR_INDEX ,&txbuf[0] ,1 ); 
}

/* read i2c device number */
uint8_t DFRobot_URM09::ReadDeviceAddress()
{
  uint8_t i = 0;
  uint8_t rxbuf[10]={0};
  Wire.beginTransmission(addr);     // transmit to device Address
  Wire.write(SLAVEADDR_INDEX);      // sends one byte
  Wire.endTransmission();           // stop transmitting
  Wire.requestFrom(addr, (uint8_t)1);
  while (Wire.available())          // slave may send less than requested
    rxbuf[i++] = Wire.read();
  
  return rxbuf[0];
}






