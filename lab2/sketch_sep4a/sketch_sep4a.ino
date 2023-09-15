#define btn1Pin 2
#define btn2Pin 3
#define ledPin 4

void setup() {
  // put your setup code here, to run once:
  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool btn1State = !digitalRead(btn1Pin);
  bool btn2State = !digitalRead(btn2Pin);

  static unsigned long int lastBlink = millis();

  if (btn1State && btn2State) {
    Serial.println("Solid light");
    digitalWrite(ledPin, HIGH);
  }else if (btn1State || btn2State) {
    Serial.println("Blinking");

    if (millis() - lastBlink > 500) {
      digitalWrite(ledPin, !digitalRead(ledPin));
      lastBlink = millis();
    }

  }else {
    Serial.println("Nothing is happening");
    digitalWrite(ledPin, LOW);
  }

}
