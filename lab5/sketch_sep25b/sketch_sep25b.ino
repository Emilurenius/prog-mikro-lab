#define potPin A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void fyllPotVerdier(int array[], int length) {
  for (int i=0;i<length;i++) {
    array[i] = analogRead(potPin);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int verdier[5] = {};
  fyllPotVerdier(verdier, 5);
  for (int i=0;i<5;i++) {
    Serial.print(verdier[i]);
    Serial.print(" <> ");
  }
  Serial.println();
}
