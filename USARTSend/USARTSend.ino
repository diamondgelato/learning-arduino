int i = 0;

void setup()
{
  Serial.begin(9600, SERIAL_8N1);
}

void loop()
{
  if (i > 255)
  {
    i = 0;
  }
  Serial.write(65);
  delay(500);
  i++;
}
