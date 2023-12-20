#include <Arduino.h>

int getDistance(int TRIG_PIN, int ECHO_PIN, uint32_t *cnt){
  
  *cnt++;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIG_PIN, HIGH);
  while (digitalRead(ECHO_PIN) == LOW);  
  unsigned long startTime = micros();

  while (digitalRead(ECHO_PIN) == HIGH);
  unsigned long endTime = micros();

  digitalWrite(TRIG_PIN, LOW);  
 

  const unsigned long duration= endTime - startTime;
  // Serial.println(duration);
  int distance= duration/29/2;
  return distance;
}