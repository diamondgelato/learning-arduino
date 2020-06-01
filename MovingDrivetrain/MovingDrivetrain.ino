const int dirPin11 = 7;
const int dirPin12 = 4;
const int dirPin21 = 9;
const int dirPin22 = 10;
const int dirPin31 = 11;
const int dirPin32 = 12;
const int speedPin1 = 3;
const int speedPin2 = 5;
const int speedPin3 = 6;
const int xPin = A0;
const int yPin = A1;
int speed1;
int speed2;
int speed3;
int xComp;
int yComp;
int initialX;
int initialY;

void setup() {
  pinMode(dirPin11, OUTPUT);
  pinMode(dirPin12, OUTPUT);
  pinMode(dirPin21, OUTPUT);
  pinMode(dirPin22, OUTPUT);
  pinMode(dirPin31, OUTPUT);
  pinMode(dirPin32, OUTPUT);
  pinMode(speedPin1, OUTPUT);
  pinMode(speedPin2, OUTPUT);
  pinMode(speedPin3, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  initialX = analogRead(xPin);
  initialY = analogRead(yPin);

  Serial.begin(9600);
}

void runMotor (int Speed, int wheel)
{
  int motorSpeed;

  if (Speed > 0)
  {
    motorSpeed = map (abs(Speed), 0, 765, 0, 255);
    forward1 (motorSpeed, wheel);
  }
  else if (Speed < 0)
  {
    motorSpeed = map (abs(Speed), 0, 765, 0, 255);
    forward2 (motorSpeed, wheel);
  }
}

void forward1(int sped, int wheel) {
  if (wheel == 1)
  {
    digitalWrite (dirPin11, HIGH);
    digitalWrite (dirPin12, LOW);
    analogWrite (speedPin1, sped);
  }
  else if (wheel == 2)
  {
    digitalWrite (dirPin21, HIGH);
    digitalWrite (dirPin22, LOW);
    analogWrite (speedPin2, sped);
  }
  else if (wheel == 3)
  {
    digitalWrite (dirPin31, HIGH);
    digitalWrite (dirPin32, LOW);
    analogWrite (speedPin3, sped);
  }
}

void forward2(int sped, int wheel) {
  if (wheel == 1)
  {
    digitalWrite (dirPin11, LOW);
    digitalWrite (dirPin12, HIGH);
    analogWrite (speedPin1, sped);
  }
  else if (wheel == 2)
  {
    digitalWrite (dirPin21, LOW);
    digitalWrite (dirPin22, HIGH);
    analogWrite (speedPin2, sped);
  }
  else if (wheel == 3)
  {
    digitalWrite (dirPin31, LOW);
    digitalWrite (dirPin32, HIGH);
    analogWrite (speedPin3, sped);
  }
}

void loop() {
  int readingX = 520 + analogRead(xPin) - initialX;
  int readingY = 525 + analogRead(yPin) - initialY;

  xComp = map(readingX, 15, 1000, -255, 255);
  yComp = map(readingY, -3, 1025, -255, 255);
  //dirAngle = atan2 (yComp, xComp);

  speed1 = xComp * (2) + yComp * (0);
  speed2 = xComp * (-1) + yComp * (-2);
  speed3 = xComp * (-1) + yComp * (2);

  //runMotor (speed1, 1);
  //runMotor (speed2, 2);
  //runMotor (speed3, 3);

  Serial.print(readingX);
  Serial.print("   ");
  Serial.print(readingY);   
}
