#define buttonPin 2
#define button2Pin 3
#define ledPin 13

float LEDdelay = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), handleInterrupt2, FALLING);
}

void handleInterrupt() {
  static long lastInterrupt = millis();
  static int debounceDelay = 100; //in millis
  if (millis() > lastInterrupt + debounceDelay) {
    LEDdelay = LEDdelay * 0.8;
    Serial.print(LEDdelay);
    Serial.println(" FASTER");
    lastInterrupt = millis();
  }
}

void handleInterrupt2() {
  static long lastInterrupt = millis();
  static int debounceDelay = 100; //in millis
  if (millis() > lastInterrupt + debounceDelay) {
    LEDdelay = LEDdelay * 1.2;
    Serial.print(LEDdelay);
    Serial.println(" SLOWER");
    lastInterrupt = millis();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  static long lastBlink = millis();

  if (millis() > lastBlink + LEDdelay) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    lastBlink = millis();
  }
}
