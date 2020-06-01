#include <SPI.h>

int DirectionPin1;
int DirectionPin2;
int SpeedPin1;

int DirectionPin3;
int DirectionPin4;
int SpeedPin2;

int trig;
int echo;
int sendTime;
int receiveTime;

int fullSpeed = 255;

void setup() {
  /*pinMode (DirectionPin1, OUTPUT);
  pinMode (DirectionPin2, OUTPUT);
  pinMode (DirectionPin3, OUTPUT);
  pinMode (DirectionPin4, OUTPUT);
  pinMode (SpeedPin1, OUTPUT);
  pinMode (SpeedPin2, OUTPUT);*/
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);

  Serial.begin (9600);
}

void loop() {
  if (digitalRead(echo) == LOW)
  {
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
  }
}
