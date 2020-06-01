void setup() {
  pinMode(0, INPUT);
  Serial.println(9600);
}

void loop() {
  Serial.println(digitalRead(0));
}
