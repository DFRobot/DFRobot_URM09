 /*!
  * file GetI2cDeviceAddress.ino
  * 
  * Connect URM09 to IIC interface of Arduino, download the program.
  * @n Open serial monitor, the temperature and distance could be checked. 
  *
  * Copyright   [DFRobot](http://www.dfrobot.com.cn)
  * Copyright   GNU Lesser General Public License
  *
  * version     V0.1
  * date        2019-6-21
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
  int16_t address = URM09.GetI2cDeviceAddress();
  if(address == URM09_NO)
    Serial.println("No I2C devices found");
  else if(address < 16)
  {
    Serial.print("I2C device found at address 0x0");
    Serial.println(address, HEX);
  }else {
    Serial.print("I2C device found at address 0x");
    Serial.println(address, HEX);
  }
  delay(1000);
}
