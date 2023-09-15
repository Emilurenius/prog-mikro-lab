#define btn1Pin 2
#define btn2Pin 3
#define buzzerPin 5

void setup() {
  // put your setup code here, to run once:
  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void dot() {
  Serial.print(".");
  tone(buzzerPin, 500);
  delay(200);
  noTone(buzzerPin);
  delay(250);
}

void dash() {
  Serial.print("-");
  tone(buzzerPin, 500);
  delay(400);
  noTone(buzzerPin);
  delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool btn1State = !digitalRead(btn1Pin);
  bool btn2State = !digitalRead(btn2Pin);

  if (btn1State) {
    dot();
  }else if (btn2State) {
    dash();
  }
}
