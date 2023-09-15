#define buzzer 10
#define ledPin 12
#define button1Pin 11
#define button2Pin 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int buttonsPressed[2] = {};
  static int bpIndex = 0;

  static int passCode = 1-2; // -1

  if (!digitalRead(button1Pin)) {
    buttonsPressed[bpIndex] = 1;
    bpIndex++;
    delay(200);
  }else if (!digitalRead(button2Pin)) {
    buttonsPressed[bpIndex] = 2;
    bpIndex++;
    delay(200);
  }

  if (bpIndex >= 2) {
    if (buttonsPressed[0] - buttonsPressed[1] == passCode) {
      Serial.println("Password is correct");
      digitalWrite(ledPin, HIGH);
    }
    else {
      Serial.println("Password is wrong");
      tone(buzzer, 500);
    }
  }
}
