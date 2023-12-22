#include <Arduino.h>

int getDistanceTest(int TRIG_PIN, int ECHO_PIN){
  // Gửi xung tín hiệu
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Đo thời gian
  unsigned long startTime = micros();
  while (digitalRead(ECHO_PIN) == LOW);
  while (digitalRead(ECHO_PIN) == HIGH);
  unsigned long endTime = micros();
  // Tính tốc độ lấy mẫu
  float samplingRate = (endTime - startTime);
  float time = samplingRate/1000;
  Serial.println("thoi gian: "+(String)time);
  // Serial.println("Tốc độ lấy mẫu: " + String(samplingRate) + " mcs");
  int distance= samplingRate/29/2;
  // float distance = (samplingRate * (endTime - startTime + 10)) / 2;
  return distance;
}