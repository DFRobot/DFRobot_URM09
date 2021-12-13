/*!
 * @file modifyI2CAddress.ino
 * @brief Modify iic device address
 * @n This example is to modify the address of the iic device
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author ZhixinLiu(zhixin.liu@dfrobot.com)
 * @version version  V1.2
 * @date 2020-9-30
 * @url https://github.com/DFRobot/DFRobot_URM09
 */
#include "DFRobot_URM09.h"

/* Create a URM09 object to communicate with IIC. */
DFRobot_URM09 URM09;

void setup() {
  Serial.begin(115200); 
  /**
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
  URM09.modifyI2CAddress(0x11);                    // Modify the i2c device number 
  delay(100);
  int16_t address = URM09.getI2CAddress();         // Read the i2c device number 
  Serial.print("the new i2c slave address is 0x");  Serial.println(address, HEX);
  while(1);
}
