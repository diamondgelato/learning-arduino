int DirectionPin1 = 2;
int DirectionPin2 = 3;
int SpeedPin1 = 6;
//Right Wheel

int DirectionPin3 = 6;
int DirectionPin4 = 7;
int SpeedPin2 = 5;
//Left Wheel

int speed = 255;

void forward (int millisec)
{
  digitalWrite (DirectionPin1, LOW);
  digitalWrite (DirectionPin2, HIGH);
  analogWrite (SpeedPin1, speed);

  digitalWrite (DirectionPin3, LOW);
  digitalWrite (DirectionPin4, HIGH);
  analogWrite (SpeedPin2, speed);

  delay(millisec);
}

void backward(int millisec)
{
  digitalWrite (DirectionPin1, HIGH);
  digitalWrite (DirectionPin2, LOW);
  analogWrite (SpeedPin1, speed);

  digitalWrite (DirectionPin3, HIGH);
  digitalWrite (DirectionPin4, LOW);
  analogWrite (SpeedPin2, speed);

  delay(millisec);
}

void right(int millisec)
{
  digitalWrite (DirectionPin1, HIGH);
  digitalWrite (DirectionPin2, LOW);
  analogWrite (SpeedPin1, speed);

  digitalWrite (DirectionPin3, LOW);
  digitalWrite (DirectionPin4, HIGH);
  analogWrite (SpeedPin2, speed);

  delay(millisec);
}

void left(int millisec)
{
  digitalWrite (DirectionPin1, LOW);
  digitalWrite (DirectionPin2, HIGH);
  analogWrite (SpeedPin1, speed);

  digitalWrite (DirectionPin3, HIGH);
  digitalWrite (DirectionPin4, LOW);
  analogWrite (SpeedPin2, speed);

  delay(millisec);
}

void boomerang()
{
  forward(5000);
  //left (1000);
}

void setup() 
{
  pinMode (DirectionPin1, OUTPUT);
  pinMode (DirectionPin2, OUTPUT);
  pinMode (SpeedPin1, OUTPUT);

  pinMode (DirectionPin3, OUTPUT);
  pinMode (DirectionPin4, OUTPUT);
  pinMode (SpeedPin2, OUTPUT);
}

void loop() 
{
  forward(100);
}
