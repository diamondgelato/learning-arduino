const int encoderPin = 5;
float state;
float mappedState;
float oldMappedState;
int rotations;
int rotationAddThresh = 500;
int rotationSubThresh = -500;

void setup() {
  // put your setup code here, to run once:
  pinMode (A5, INPUT);
  Serial.begin(9600);
  rotations = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  state = analogRead(A5);

  mappedState = myMap(state, 0, 832, 0, 1023); 

  if (oldMappedState - mappedState > rotationAddThresh)
  {
    rotations = rotations + 1;
  }
  else if (oldMappedState - mappedState < rotationSubThresh)
  {
    rotations = rotations - 1;
  }

  Serial.println((1023*rotations) + mappedState);
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
