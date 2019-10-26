#include <Servo.h>

const int SERVO = 9;
const int TRIGGER = 3;
const int ECHO = 5;

const int RED = 9;

int counter = 0;

Servo servo;

long duration;
int distance;

int redBgt = 0;

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

void setLed() {

  if(distance < 100) {
    redBgt = map(distance, 100, 0, 50, 250);
    Serial.print(" Brightness: ");
    Serial.print(redBgt);
  } else {
    redBgt = 1;  
  }

  analogWrite(RED, redBgt);
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
}

void setup() {
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  
  servo.attach(SERVO);
}

void loop() {
//  if(counter >= 200) {
    checkEcho();
    counter = 0;
//  }
//  counter++;
  
  setLed();
//  delay(30);
}
