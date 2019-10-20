#include <Servo.h>

const int SERVO = 9;
const int TRIGGER = 3;
const int ECHO = 5;

Servo servo;

void setup() {
  Serial.begin(9600);
  
  servo.attach(SERVO);
}

void loop() {
//  servo.write(random(0, 360));
  delay(500);
}
