#include "../lib/waitTime.cpp"
#include "../lib/test.cpp"

const unsigned int TRIG_PIN = 1;  //RX
const unsigned int ECHO_PIN = 2;  // TX
const unsigned int BAUD_RATE = 9600;
const unsigned int led = 13;  //led
const int arry = 5;
const int del = 50;
const int max = 400;
const int min = 60;
const long intervalSensor = 3;
const long intervalPrint = 2;
uint32_t cnt = 0;
// static int distance = 0;
int distancePre = 0;
// int distance =0;

int getDistance(int TRIG_PIN, int ECHO_PIN){
  
  // running time 20mcs 
  digitalWrite(TRIG_PIN, LOW);
  //delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(1);
  digitalWrite(TRIG_PIN, LOW);
  while (digitalRead(ECHO_PIN) == LOW);  //60ms
  uint32_t startTime = micros();
  while (digitalRead(ECHO_PIN) == HIGH);
  uint32_t endTime = micros();
  digitalWrite(TRIG_PIN, LOW);  
 
  const uint32_t duration= endTime - startTime;
  Serial.println("thoi gian cho: "+(String)duration);
  // Serial.println(duration);
  int distance= duration/29/2;
  return distance;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(BAUD_RATE);
}



void loop() {
  static unsigned long previousSensorMillis = 0;
  static unsigned long previousPrintMillis = 0;
  static uint32_t time = micros();
  static int distance;
  
  distance = getDistance(TRIG_PIN, ECHO_PIN);
  cnt++;
  if (distance > max) {
    digitalWrite(led, HIGH);
    return;
  }
  if (cnt >=100)
  {
    cnt= 0;
    uint32_t total_time = micros()-time;
    time = micros();
    Serial.print("Avg time: ");
    Serial.println(total_time/100);
  }
  if (waitTime(&previousPrintMillis, intervalPrint)) {
    if (distance < min) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println();
}
