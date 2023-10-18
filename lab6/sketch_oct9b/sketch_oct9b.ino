#define DHTPIN 5
#define buttonPin 2
#define button2Pin 3
#include "DHT.h"

#define DHTTYPE DHT11   // DHT 11

bool readFlag = false;
bool getAverageFlag = true;

struct tempHum {
  float temp;
  float hum;
};

tempHum tempHumArr[100] = {};
int tempHumI = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {writeRaw
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), handleInterrupt2, FALLING);

  dht.begin();
}

void handleInterrupt() {
  static long lastInterrupt = millis();
  static int debounceDelay = 100; //in millis
  if (millis() > lastInterrupt + debounceDelay) {
    readFlag = true;
  }
}

void handleInterrupt2() {
  static long lastInterrupt = millis();
  static int debounceDelay = 100; //in millis
  if (millis() > lastInterrupt + debounceDelay) {
    getAverageFlag = true;
  }
}

int getTemp() {
  float t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println("Failed to read from DHT!!");
    return 4004;
  }
  else {
    return t;
  }
}

int getHum() {
  float t = dht.readHumidity();
  if (isnan(t)) {
    Serial.println("Failed to read from DHT!!");
    return 4004;
  }
  else {
    return t;
  }
}

float getAverageTemp(float temps[], int tempsLen) {
  float average = 0;
  for (int i=0;i<tempsLen;i++) {
    average += temps[i];
  }
  average = average / tempsLen;
  return average;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (readFlag) {
    tempHumArr[tempHumI].temp = getTemp();
    tempHumArr[tempHumI].hum = getHum();
    readFlag ++;
    if (readFlag >= 100) {
      readFlag = 0;
    }
    Serial.println("Value saved");
    readFlag = false;
  }

  if (getAverageFlag) {
    int tempAverage = 0;
    int humAverage = 0;
    int valsAmount = 0;
    for (int i=0; i<100; i++) {
      if (tempHumArr[tempHumI].temp != 0) {
        valsAmount += 1;
        tempAverage += tempHumArr[tempHumI].temp;
        humAverage += tempHumArr[tempHumI].hum;
      }
    }
    tempAverage = tempAverage / valsAmount;
    humAverage = humAverage / valsAmount;
    Serial.println(tempAverage);
    Serial.println(humAverage);
    getAverageFlag = false;
  }
}
