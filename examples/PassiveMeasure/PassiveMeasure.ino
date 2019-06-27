/*!
 * PassiveMesure.ino
 *
 * Download this demo to test config to URM09, connect sensor through IIC interface
 * Data will print on your serial monitor
 *
 * This example is the ultrasonic passive measurement distance and the temperature of the module.
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
  while(!URM09.begin())
  {
    Serial.println("I2c device number error ");
    delay(1000);
  }
  /*
   The module is configured in automatic mode or passive ，
     MEASURE_MODE_AUTOMATIC       // automatic mode
     MEASURE_MODE_PASSIVE         // passive mode
  
   The measurement distance is set to 500,300,100 
     MEASURE_RANG_500              // Ranging from 500 
     MEASURE_RANG_300              // Ranging from 300 
     MEASURE_RANG_150              // Ranging from 100 
  */
  URM09.SetModeRange(MEASURE_MODE_PASSIVE ,MEASURE_RANG_500);   
  delay(100);
}

void loop() {
  URM09.SetMeasurement();                          // Send ranging command 
  delay(100);
  int16_t dist = URM09.i2cReadDistance();          // Read distance register
  int16_t temp = URM09.i2cReadTemperature();       // Read temperature register 
  Serial.print(dist, DEC); Serial.print(" cm------"); Serial.print((float)temp / 10, 1); Serial.println(" C");
  
  delay(100);

}