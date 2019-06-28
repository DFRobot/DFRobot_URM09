/*!
 * ModifyDeviceAddress.ino
 *
 * Download this demo to test config to URM09, connect sensor through IIC interface
 * Data will print on your serial monitor
 *
 * This example is to set the device number of the urm09.
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

void setup() {
  
  Serial.begin(9600); 
  /*
   * I2c device number 1-127
   * When the i2c device number is not passed, the default parameter is 0x11
   */
  while(!URM09.begin())
  {
    Serial.println("I2c device number error");
    delay(1000);
  }
  delay(100);
}

void loop() {
  URM09.ModifyDeviceAddress(0x11);                     //Modify the i2c device number 
  delay(100);
  
  int16_t address = URM09.ReadDeviceAddress();         //Read the i2c device number 
  Serial.print("the new i2c slave address is 0x");  Serial.println(address, HEX);
  
  while(1);
}
