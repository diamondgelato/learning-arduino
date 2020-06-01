int x;
void setup() {
  Serial.begin(9600);
}

void loop()
{
  x = Serial.read();
  //if (x != -1)
    Serial.println (x);
}
