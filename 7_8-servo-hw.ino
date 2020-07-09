#include <Servo.h>
Servo myServo;
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
#define POTPIN A0
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  myServo.attach(3);
  Serial.begin(9600);
  Serial.println(F("test!"));

  dht.begin();
}

void loop() {
 
  float t = dht.readTemperature();
 

if (isnan(t)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
}
  Serial.print("Your temp is -> ");
  Serial.println(t);

  int servoPos = map(t,20,30,0,180);
  myServo.write(servoPos);
  delay(50);
}
