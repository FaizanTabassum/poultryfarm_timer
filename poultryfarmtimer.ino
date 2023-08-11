#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;
const int relay1 = 4;
const int relay2 = 5;
const int in1 = 8;
const int in2 = 9;

void actuatorPull();
void actuatorPush();
void turnOFF();
int counter = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //   // clear /EOSC bit to ensure that the clock runs on battery power
  // Wire.beginTransmission(0x68); // address DS3231
  // Wire.write(0x0E); // select register
  // Wire.write(0b00011100); // write register bitmap, bit 7 is /EOSC
  // Wire.endTransmission();

  if (rtc.lostPower()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(relay1, OUTPUT);// set pin as output for relay 1
  pinMode(relay2, OUTPUT);// set pin as output for relay 2
  pinMode(in1, INPUT_PULLUP);
  pinMode(in2, INPUT_PULLUP);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
}

void loop() {
  DateTime now = rtc.now();
  int currentHour = now.hour();
  int currentMinute = now.minute();
  int currentSecond = now.second();
  Serial.print(currentHour);
  Serial.print(":");
  Serial.print(currentMinute);
  Serial.print(" currentcount:");
  Serial.println(counter);
// && (currentSecond == 0)
  if ((currentHour >= 9 && currentHour < 13) || currentHour == 16) {
    if ((currentMinute % 10 == 0)) {
      counter++;
      actuatorPush();
      delay(30000); // pushes the actuator for 30 seconds 
      actuatorPull(); // pulls back the actuator after 30 seconds
      delay(30000);
      turnOFF();//turns off the actuator after 30 seconds to save power 
      delay(100);
    }
  }

// bypass feature to turn on and off the actuator whenever required 
if(digitalRead(in1) == LOW){actuatorPush();}
else if(digitalRead(in2) == LOW){actuatorPull();}
else{turnOFF();}

  delay(1000); // Wait for 1 second before checking the time again
}

void actuatorPush()
{
    digitalWrite(relay1, LOW);// turn relay 1 ON
    digitalWrite(relay2, HIGH);// turn relay 2 OFF  

}

void actuatorPull()
{
    digitalWrite(relay1, HIGH);// turn relay 1 OFF
    digitalWrite(relay2, LOW);// turn relay 2 ON
 
}
void turnOFF()
{
    digitalWrite(relay1, HIGH);// turn relay 1 OFF
    digitalWrite(relay2, HIGH);// turn relay 2 OFF

}