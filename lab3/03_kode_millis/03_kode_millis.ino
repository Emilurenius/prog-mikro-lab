#define ledPin 12
#define buttonPin 7
#define potPin A7

void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);
 Serial.begin(9600);
}

void loop() {
  static unsigned long lastChange = 0;

  int interval = map(analogRead(potPin), 0, 1024, 0, 10000);
  Serial.println(interval);

  int buttonState = !digitalRead(buttonPin);
  static int ledState = LOW;
  if(buttonState == HIGH){
    ledState = HIGH;
  }
  else{
    if(millis() >= lastChange + interval){
      //bytte tilstand på LED
      /*
      if(ledState == HIGH){
        ledState = LOW;
      }
      else {
        ledState = HIGH;
      }
      */
      ledState = !ledState;
      lastChange = millis();
    }
  }

  digitalWrite(ledPin, ledState);
   /*
  if(buttonState == HIGH){
    digitalWrite(ledPin, HIGH);
  }
 
  else{
    digitalWrite(ledPin,HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    delay(2000);
  }
  */
}
