 /*!
  * @file  GetI2cDeviceAddress.ino
  * @brief Get iic device address
  * @n This example is to get the iic device address and print it to the serial port
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
