#define ledPin 7
#define buzzer 6

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long lastBlink = millis();
  static int ledState = 0;
  static int serialIn[2] = {};
  static int serialInI = 0;

  if (Serial.available()) {
    while (serialInI <= 2) {
      serialIn[serialInI] = Serial.parseInt();
      serialInI++;
    }
    serialInI = 0;
  }

  switch (serialIn[0]) {
    case 1:
      if (millis() - lastBlink > serialIn[1]) {
        ledState = !ledState;
        lastBlink = millis();
        break;
        case 2:
          ledState = 0;
          digitalWrite(buzzer, HIGH);
          // tone(buzzer, serialIn[1]);
          break;
        default:
          ledState = 0;
          digitalWrite(buzzer, LOW);
          // notone(buzzer);
          break;
      }
  }

  digitalWrite(ledPin, ledState);
}
