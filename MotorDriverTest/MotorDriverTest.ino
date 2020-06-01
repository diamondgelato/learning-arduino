const int DirPin1 = 6;
const int DirPin2 = 7;
const int speedPin = 5;

int speed = 45;

void setup() {
  pinMode (DirPin1, OUTPUT);
  pinMode (DirPin2, OUTPUT);
  pinMode (speedPin, OUTPUT);
}

void loop() {
  forward();
}

void forward() {
  digitalWrite (DirPin1, LOW);
  digitalWrite (DirPin2, HIGH);
  analogWrite (speedPin, speed);
}
