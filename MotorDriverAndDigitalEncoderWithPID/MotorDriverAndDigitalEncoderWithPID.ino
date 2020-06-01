const int digitalPinA = 2;
const int digitalPinB = 3;
const int DirPin1 = 6;
const int DirPin2 = 7;
const int speedPin = 5;
const int zeroSpeed = 0;
bool pinA = LOW;
bool pinB = LOW;
volatile long rotation;                           //for quantity of rotation
volatile byte isClockwise;                        //for direction of rotation
volatile bool currentA;
volatile bool currentB;
volatile bool lastA;
int Speed = 255;
int target = 0;
int error;
int timer;
int errorIntegral;
int errorDerivative;
int errorTotal;
int lastError;
int lastTime;

void setup() {
  pinMode(digitalPinA, INPUT_PULLUP);
  pinMode(digitalPinB, INPUT_PULLUP);
  pinMode (DirPin1, OUTPUT);
  pinMode (DirPin2, OUTPUT);
  pinMode (speedPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(digitalPinA), check, CHANGE);
  Serial.begin(9600);
  rotation = 0;
  Speed = 255;
  target = 0;
  error = 0;
  timer = 0;
  errorIntegral = 0;
  errorDerivative = 0;
  errorTotal = 0;
  lastError = 0;
  lastTime = 0;
}

void forward1(int sped) {
  digitalWrite (DirPin1, HIGH);
  digitalWrite (DirPin2, LOW);
  analogWrite (speedPin, sped);
}

void forward2(int sped) {
  digitalWrite (DirPin1, LOW);
  digitalWrite (DirPin2, HIGH);
  analogWrite (speedPin, sped);
}

void noMovement()
{
  digitalWrite (DirPin1, HIGH);
  digitalWrite (DirPin2, HIGH);
  analogWrite (speedPin, zeroSpeed);
}

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
  target = 5000;

  timer = millis();
  error = target - rotation;
  //errorIntegral += error;
  errorDerivative = (error - lastError) / (timer - lastTime);

  Speed = abs((error * (0.2)) + (errorDerivative * (2))); // + errorIntegral * (0.01));
  //Speed = constrain(Speed, 69, 255);

  if (error > 0)
  {
    Speed = constrain(Speed, 70, 255);
    forward1 (Speed);
  }
  else if (error < 0)
  {
    Speed = constrain(Speed, 50, 255);
    forward2 (Speed);
  }
  else if (error = 0)
  {
    noMovement ();
  }

  Serial.print(rotation);
  Serial.print("  ");
  Serial.println(Speed);

  lastError = error;
  lastTime = timer;
}
