const int interruptPin = 0;
const int ledPin = 13;
bool ledOn = LOW;

void setup() {
  // put your setup code here, to run once:
  attachInterrupt (0, blink, FALLING);
  pinMode (ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void blink()
{
  state = digitalRead(buttonPin);
  
  if (millis() - lastDebounceTime > DebounceThresh)
  {
    if (currentState != state)
    {
      currentState = state;

      if (currentState == HIGH)
      {
        ledOn = !ledOn;
      }
    }
  }

  if (lastState != state)
  {
    lastDebounceTime = millis();
  }
  
  lastState = currentState;
  
  ledOn = !ledOn;
  digitalWrite (ledPin, ledOn);
}
