const int buttonPin = 2;
const int ledPin1 = 6;
const int ledPin2 = 7;
const int ledPin3 = 8;
volatile bool currentState;
volatile bool lastState;
volatile bool state;
volatile long lastDebounceTime;
volatile int DebounceThresh;
volatile byte buttonPress;

void setup() {
  pinMode (buttonPin, INPUT);
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode (ledPin3, OUTPUT);
  Serial.begin (9600);
  //attachInterrupt (0, debounce, CHANGE);
}

void loop() {
  state = digitalRead(buttonPin);
  
  if (lastState != state)
  {
    lastDebounceTime = millis();
  }
  
  if (millis() - lastDebounceTime > 200)
  {
    if (buttonPress == 1)
    {
      digitalWrite (ledPin1, HIGH);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, LOW);
    }
    else if (buttonPress == 2)
    {
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
    }
    else if (buttonPress == 3)
    {
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
    }

    Serial.println(buttonPress);
    buttonPress = 0;
  }

  if (millis() - lastDebounceTime > DebounceThresh)
  {
    debounce();
  }
}

void debounce() {
  if (currentState != state)
  {
    currentState = state;

    if (currentState == HIGH)
    {
      buttonPress = buttonPress + 1;
    }
  }

  lastState = currentState;
}
