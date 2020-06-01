const int encoderPin = A0;

void setup() {
  pinMode (encoderPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(encoderPin));
}
