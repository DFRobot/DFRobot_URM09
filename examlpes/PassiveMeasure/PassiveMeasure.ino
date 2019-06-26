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
  URM09.SetModeRange(MEASURE_MODE_PASSIVE ,MEASURE_RANG_500);   // The module is configured in passive mode and the ranging range is set to 500cm 
  delay(100);
}

void loop() {
  URM09.SetMeasurement(CMD_DISTANCE_MEASURE);                   // Write command register and send ranging command 
  delay(100);
  int16_t dist = URM09.i2cReadDistance();                       // Read distance register
  int16_t temp = URM09.i2cReadTemperature();                    // Read temperature register 
  Serial.print(dist, DEC);
  Serial.print("cm------");
  Serial.print((float)temp / 10, 1);
  Serial.println("℃");
  delay(500);

}