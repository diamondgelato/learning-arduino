const int digitalPinA = 2;
const int digitalPinB = 3;
bool pinA = LOW;
bool pinB = LOW;
volatile long rotation;                           //for quantity of rotation
volatile byte isClockwise;                        //for direction of rotation
volatile bool currentA;
volatile bool currentB;
volatile bool lastA;

void setup() {
  pinMode(digitalPinA, INPUT_PULLUP);
  pinMode(digitalPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(digitalPinA), check, CHANGE);
  Serial.begin(9600);
  rotation = 0;
}

//Loop with interrupts

void check() {
  currentA = digitalRead(digitalPinA);
  currentB = digitalRead(digitalPinB);
  if (lastA == LOW && currentA == HIGH)
  { if (currentB == LOW)
    {
      rotation++;
      isClockwise = HIGH;
    }
    else if (currentB == HIGH)
    {
      rotation--;
      isClockwise = LOW;
    }
  }
  lastA = currentA;
}

void loop() {
  Serial.println (rotation);
  //Serial.println (digitalRead(digitalPinB));
}
