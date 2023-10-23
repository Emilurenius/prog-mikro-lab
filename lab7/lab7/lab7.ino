#define btn1 2
#define btn2 3
#define btn3 18
#define rPin 9
#define gPin 10
#define bPin 11
#define potPin A0
#define ledPin 8

#define debounceDelay 300
#define blinkDelay 1000

enum lightMode {digitalRead
  off,
  on,
  blinking,
  emergencyStop
};

enum color {
  red,
  green,
  blue
};

lightMode state = off;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  static unsigned long lastbtnPress = millis();
  static bool ledState = false;
  static color currentColor = red;

  unsigned int potVal = analogRead(potPin);

  // put your main code here, to run repeatedly:
  if (lastbtnPress + debounceDelay < millis()) { 
      lastbtnPress = millis();
    if (!digitalRead(btn1) && state != emergencyStop) {
      state = state +1;
      if (state > 2) {
        state = 0;
      }
    }
    if (!digitalRead(btn2) && state != emergencyStop) {
      lastbtnPress = millis();
      state = state - 1;
      if (state < 0) {
        state = 2;
      }
    }
    if (!digitalRead(btn3)) {
      lastbtnPress = millis();
      state = emergencyStop;
    }
  }

  switch (state) {
    case off:
      ledState = false;
      break;
    case on:
      ledState = true;
      break;
    case blinking:
      static unsigned long lastBlink = millis();
      if (lastBlink + blinkDelay < millis()) {
        ledState = !ledState;
        lastBlink = millis();
      }
      break;
    case emergencyStop:
      ledState = false;
      break;
  }

  switch (currentColor) {
    case red:
      if (potVal < 750) {
        currentColor = blue;
      }
      break;
    case green:
      if (potVal > 300) {
        currentColor = blue;
      }
      break;
    case blue:
      if (potVal < 250) {
        currentColor = green;
      }
      else if (potVal > 850) {
        currentColor = red;
      }
  }

  digitalWrite( rPin, currentColor == red && ledState );
  digitalWrite( gPin, currentColor == green && ledState );
  digitalWrite( bPin, currentColor == blue && ledState );
  digitalWrite( ledPin, ledState );
}
