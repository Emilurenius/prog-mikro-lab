#define redPin 2
#define yellowPin 3
#define bluePin 4
#define potPin A0
#define buttonPin 18

bool buttonState = false;

int state = 0;
int delayMS = 500;

bool states[4][3] = {
  {true, false, false},
  {true, true, false},
  {false, false, true},
  {false, true, false}
};

int stateDelays[4] = {3, 1, 3, 1};

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i=0; i<4; i++) {
    delayMS = analogRead(potPin);
    digitalWrite(redPin, states[i][0]);
    digitalWrite(yellowPin, states[i][1]);
    digitalWrite(bluePin, states[i][2]);
    delay(analogRead(potPin) * stateDelays[i]);
  }
}
