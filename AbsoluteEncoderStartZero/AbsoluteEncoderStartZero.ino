const int encoderPin = A0;
float state;
float mappedState;
float oldMappedState;
float initialMappedState;
int rotations;
int rotationAddThresh = 300;
int rotationSubThresh = -300;

void setup() {
  // put your setup code here, to run once:
  pinMode (encoderPin, INPUT);
  Serial.begin(9600);
  
  rotations = 0;
  //initialMappedState = myMap(analogRead(A5), 0, 832, 0, 1023);
  initialMappedState = analogRead(encoderPin);
  oldMappedState = analogRead(encoderPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = analogRead(encoderPin);

  //mappedState = myMap(state, 0, 832, 0, 1023);
  mappedState = state;

  if (oldMappedState - mappedState > rotationAddThresh)
  {
    rotations = rotations + 1;
  }
  else if (oldMappedState - mappedState < rotationSubThresh)
  {
    rotations = rotations - 1;
  }

  Serial.print((1023*rotations) + mappedState - initialMappedState);
  //Serial.print("  ");
  //Serial.print(mappedState);
  //Serial.print("  ");
  //Serial.print(initialMappedState);
  //Serial.print("  ");
  //Serial.println(rotations);
  oldMappedState = mappedState;
}

int myMap (float inp, float sourceLow, float sourceHigh, float outLow, float outHigh)
{
  float output;
  float sourceRange = sourceHigh - sourceLow;
  float outRange = outHigh - outLow;

  if (inp >= sourceLow && inp <= sourceHigh)
  {
    output = outLow + (inp-sourceLow)*(outRange/sourceRange);
  }
  else if (inp < sourceLow)
  {
    output = outLow;
  }
  else if (inp > sourceHigh)
  {
    output = sourceHigh;
  }

  return output;
}
