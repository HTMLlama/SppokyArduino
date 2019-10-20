#include <Servo.h>

const int SERVO = 9;
const int TRIGGER = 3;
const int ECHO = 5;

Servo servo;

long duration;
int distance;

void checkEcho() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGGER, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("\n Distance: ");
  Serial.print(distance);

}

void setup() {
  Serial.begin(9600);

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  
//  servo.attach(SERVO);
}

void loop() {
//  servo.write(random(180));
  checkEcho();
  delay(150);
}
