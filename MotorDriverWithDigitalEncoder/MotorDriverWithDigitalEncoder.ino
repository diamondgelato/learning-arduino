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
  digitalWrite (DirPin1, LOW);
  digitalWrite (DirPin2, LOW);
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
  target = -5000;

  if (target > 0)
  {
    if (target > 1000)
    {
      if (rotation < (target - 360))
      {
        Speed = 255;
      }
      else if (rotation > (target - 360) && Speed > 0)
      {
        Speed = 255 - (3 / 2) * (rotation - (target - 360));
      }
    }
    else if (target < 1000 && target > 0)
    {
      if (rotation < (target - 120))
      {
        Speed = 100;
      }
      else if (rotation > (target - 120))
      {
        Speed = 100 - (3 / 2) * (rotation - (target - 120));
      }
    }
  }
  else if (target < 0)
  {
    if (target < -1000)
    {
      if (rotation > (target + 450))
      {
        Speed = 255;
      }
      else if (rotation < (target + 450) && Speed > 0)// && rotation > -5000)// && Speed > 30)
      {
        Speed = 255 + (3 / 2) * (rotation - (target + 450));
      }
    }
    else if (target > -1000 && target < 0)
    {
      if (rotation > (target + 120))
      {
        Speed = 100;
      }
      else if (rotation < (target + 120))
      {
        Speed = 100 + (3 / 2) * (rotation - (target + 120));
      }
    }
  }

  //if (target < 0)
  //{
  Serial.print (rotation);
  Serial.println (Speed);

  if (target < 0)
  {
    if (Speed < 0)
      forward2 (0);
    else
      forward2(Speed);
  }
  else if (target > 0)
  {
    if (Speed < 0)
      forward1 (0);
    else
      forward1(Speed);
  }
  //}
}
