void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void skrivStjerner(int stjerner) {
  for (int i=0;i<stjerner;i++) {
    Serial.print('*');
  }
  Serial.println(' ');
}

void skrivMangeStjerner(int stjerner) {
  for (int i=0;i<stjerner;i++) {
    skrivStjerner(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  skrivMangeStjerner(6);
  delay(1000);
}