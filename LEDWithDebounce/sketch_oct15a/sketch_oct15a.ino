int ledPin = 13;
int buttonPin = 8;
boolean ledOn = LOW;
long lastDebounceTime;
long DebounceThresh = 50;
bool currentState = LOW;
bool lastState;
bool state;

void setup() {
  // put your setup code here, to run once:
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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

  if (lastState != state)
  {
    lastDebounceTime = millis();
  }
  
  digitalWrite (ledPin, ledOn);

  lastState = currentState;
}
