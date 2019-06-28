/*!
 * GetI2cDeviceAddress.ino
 *
 * Download this demo to test config to URM09, connect sensor through IIC interface
 * Data will print on your serial monitor
 *
 * This example is to get the device number of the urm09.
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2016
 * Copyright   GNU Lesser General Public License
 *
 * version  V1.0
 * date  25/06/2019
 */
#include "DFRobot_URM09.h"

/* Create a URM09 object to communicate with IIC. */
DFRobot_URM09 URM09;

void setup()
{
  Serial.begin(9600); 
}

void loop()
{
  int16_t address = URM09.GetI2cDeviceAddress();       //Get i2c device number
  if(address < 0){
    Serial.println("No I2C devices found");
  }else if(address < 16){
    Serial.print("I2C device found at address 0x0"); Serial.println(address, HEX);
  }else {
    Serial.print("I2C device found at address 0x");  Serial.println(address, HEX);
  }
  delay(1000);
}
