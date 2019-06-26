  /*!
  * file URM09PassiveMesure.ino
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


void setup() {
  
  Serial.begin(9600); 
  while(URM09.begin() == URM09_NO)
  {
    Serial.println("begin is flase");
    delay(1000);
  }
  delay(100);
}

void loop() {

  URM09.ModifyDeviceAddress(0x11);
  delay(100);
  
  int16_t address = URM09.ReadDeviceAddress();
  Serial.print("the new i2c slave address is 0x");
  Serial.println(address, HEX);
  
  while(1);
}
