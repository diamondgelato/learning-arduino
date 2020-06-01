int echo = 3;
int trig = 4;
long sendTime;
long receiveTime;
long pulseTime;
float distance;

void setup() {
  pinMode (echo, INPUT_PULLUP);
  pinMode (trig, OUTPUT);
  pinMode (LED_BUILTIN, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(echo), receivePulse, RISING);

  Serial.begin (9600);
}

void loop() {
  if (digitalRead (echo) == LOW)
  {
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
  }

  pulseTime = pulseIn(echo, HIGH);
  distance = pulseTime/58.0;
  Serial.println(pulseTime);
}
