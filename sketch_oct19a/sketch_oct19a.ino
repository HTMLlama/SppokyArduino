
const int FAN = 6;
const int TRIGGER = 3;
const int ECHO = 5;

const int RED = 9;

int GAP_SPACE = 120;

long duration;
int distance;

int redBgt = 0;

void setLed() {

  if(distance < GAP_SPACE) {
    redBgt = map(distance, GAP_SPACE, 0, 5, 250);

    digitalWrite(FAN, HIGH);
    
    Serial.print(" Brightness: ");
    Serial.print(redBgt);
  } else {
    redBgt = 1;  
    digitalWrite(FAN, LOW);
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
  pinMode(FAN, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  
}

void loop() {
  checkEcho();
  setLed();
}
