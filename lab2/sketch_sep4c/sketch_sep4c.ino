#define ledPin 4

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int delayMS = 10;
  unsigned long int lastBlink = millis();
  while (delayMS <= 5000) {
    if (millis() - lastBlink > delayMS) {
      digitalWrite(ledPin, !digitalRead(ledPin));
      lastBlink = millis();
      delayMS += 10;
    }
  }
}
