/*!
 * @file AutoMesure.ino
 * @brief Automatic acquisition of distance and temperature.
 * @n This example is the ultrasonic automatic measurement of distance and read the temperature of the module printed on the serial port
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
  while(!URM09.begin()){
    Serial.println("I2c device number error");
    delay(1000);
  }
  /**
   * The module is configured in automatic mode or passive
   *  MEASURE_MODE_AUTOMATIC       automatic mode
   *  MEASURE_MODE_PASSIVE         passive mode
   * The measurement distance is set to 500,300,150 
   *  MEASURE_RANG_500             Ranging from 500 
   *  MEASURE_RANG_300             Ranging from 300 
   *  MEASURE_RANG_150             Ranging from 150 
  */
  URM09.setModeRange(MEASURE_MODE_AUTOMATIC ,MEASURE_RANG_500);
  delay(100);
}

void loop() {
  int16_t dist = URM09.getDistance();                // Read distance
  float temp = URM09.getTemperature();               // Read temperature
  Serial.print(dist, DEC); Serial.print(" cm------");
  Serial.print(temp, 1); Serial.println(" C");
  delay(100);
}