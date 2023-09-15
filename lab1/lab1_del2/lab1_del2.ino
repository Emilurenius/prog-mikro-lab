#define buttonPin 18
#define ledPin 2

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonState);
  Serial.println(buttonState);
}
