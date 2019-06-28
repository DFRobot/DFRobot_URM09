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

#include "DFRobot_URM09.h"
#include <Arduino.h>
#include <Wire.h>


DFRobot_URM09::DFRobot_URM09()
{
}

DFRobot_URM09::~DFRobot_URM09()
{
}

/* join i2c bus (address optional for master) */
bool DFRobot_URM09::begin(uint8_t addr0)
{
  this->_addr = addr0;              // Set the host address 
  Wire.begin();                     // connecting the i2c bus 
  Wire.beginTransmission(_addr);
  if(Wire.endTransmission() == 0)
    return true;
  return false;
}

/* Set the automatic mode or the passive mode and the measurement distance */
void DFRobot_URM09::SetModeRange(uint8_t Range ,uint8_t SetMode)
{  
  txbuf[0] = (uint8_t)(Range | SetMode);   // Mode and range write to configuration register. 
  i2cWriteTemDistance(eCFG_INDEX , &txbuf[0], 1 );
}

/* Write command registers and send ranging commands in passive mode */
void DFRobot_URM09::SetMeasurement()
{ 
  txbuf[0] = CMD_DISTANCE_MEASURE;
  i2cWriteTemDistance(eCMD_INDEX , &txbuf[0],1 );
}

/* Read the temperature data of the register */
int16_t DFRobot_URM09::i2cReadTemperature()
{
  uint8_t i = 0;
  uint8_t rxbuf[10] = {0};
  Wire.beginTransmission(_addr);       // transmit to device Address
  Wire.write(eTEMP_H_INDEX);            // sends one byte
  Wire.endTransmission();              // stop transmitting
  Wire.requestFrom(_addr, (uint8_t)2);
  while (Wire.available())             // slave may send less than requested
    rxbuf[i++] = Wire.read();
  
  return ((int16_t)rxbuf[0] << 8) + rxbuf[1];
}

/* Read the distance data of the register  */
int16_t DFRobot_URM09::i2cReadDistance()
{
  uint8_t i = 0;
  uint8_t rxbuf[10] = {0};
    
  Wire.beginTransmission(_addr);       // transmit to device Address
  Wire.write(eDIST_H_INDEX);            // sends one byte
  Wire.endTransmission();              // stop transmitting
  Wire.requestFrom(_addr, (uint8_t)2);
  while (Wire.available())             // slave may send less than requested
    rxbuf[i++] = Wire.read();
  
  return ((int16_t)rxbuf[0] << 8) + rxbuf[1];
}

/* Write data to the i2c register  */
void DFRobot_URM09::i2cWriteTemDistance(uint8_t Reg , uint8_t *pdata, uint8_t datalen )
{
  Wire.beginTransmission(_addr);       // transmit to device #8
  Wire.write(Reg);                     // sends one byte
  for (uint8_t i = 0; i < datalen; i++) 
    Wire.write(pdata[i]);
  Wire.endTransmission();              // stop transmitting
}

/* Get the i2c device address */
int16_t DFRobot_URM09::GetI2cDeviceAddress()
{
  Wire.begin();                         // connecting the i2c bus 
  uint8_t error ,address;
  // the Write.endTransmisstion to see if a device did acknowledge to the address.
  for (address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
      return address;
  }
  return -1;
}

/* Modify i2c device number  */
void DFRobot_URM09::ModifyDeviceAddress(uint8_t Address)
{
  txbuf[0] = Address;
  // Write the new address xxxx to the address register. 
  i2cWriteTemDistance(eSLAVEADDR_INDEX ,&txbuf[0] ,1 ); 
}

/* read i2c device number */
uint8_t DFRobot_URM09::ReadDeviceAddress()
{
  uint8_t i = 0;
  uint8_t rxbuf[10]={0};
  Wire.beginTransmission(_addr);       // transmit to device Address
  Wire.write(eSLAVEADDR_INDEX);         // sends one byte
  Wire.endTransmission();              // stop transmitting
  Wire.requestFrom(_addr, (uint8_t)1);
  while (Wire.available())             // slave may send less than requested
    rxbuf[i++] = Wire.read();
  
  return rxbuf[0];
}






