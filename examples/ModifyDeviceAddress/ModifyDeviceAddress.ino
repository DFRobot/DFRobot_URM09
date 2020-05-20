 /*!
  * @file  ModifyDeviceAddress.ino
  * @brief Modify iic device address
  * @n This example is to modify the address of the iic device
  *
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version     version  V1.1
  * @date        2020-5-20
  * @get         from https://www.dfrobot.com
  * @url   */
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
