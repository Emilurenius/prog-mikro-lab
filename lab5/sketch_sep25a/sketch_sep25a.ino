void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int abs1(int tall) {
  return abs(tall);
}

void abs2(int* tall) {
  *tall = abs(*tall);
}

void loop(){
  int tall1 = -2;
  int tall2 = -7;
  //så kaller jeg noen funksjoner
  tall1 = abs1(tall1);
  abs2(&tall2);
  Serial.print(tall1);
  Serial.print(tall2);
  while(1);
}
