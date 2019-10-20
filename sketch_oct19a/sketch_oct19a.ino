#include <Servo.h>

const int SERVO = 9;
const int TRIGGER = 3;
const int ECHO = 5;

Servo servo;

long duration;
int distance;

void runServo() {
  servo.write(1);
  delay(500);
  servo.write(90);
  delay(500);
  servo.write(180);
  delay(500);
  servo.write(90);
  delay(500);
}

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

  if(distance < 20) {
    runServo();  
  }

}

void setup() {
  Serial.begin(9600);

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  
  servo.attach(SERVO);
}

void loop() {
//  servo.write(random(180));
  checkEcho();
  delay(150);
}
