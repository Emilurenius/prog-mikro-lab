#define ledPin 12
#define loops 15

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, LOW);
  for (int i=0;i<loops;i++) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    delay(500);
    digitalWrite(ledPin, !digitalRead(ledPin));
    delay(500);
  }
  while (true) {}
}
