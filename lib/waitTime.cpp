#include "Arduino.h"

bool waitTime(unsigned long* currentTime,long interval ) {
  // Lấy giá trị thời gian hiện tại từ millis()
  unsigned long currentMillis = millis();
  
  // Kiểm tra sự chênh lệch và trả về kết quả
  if (static_cast<long>(currentMillis - *currentTime) > interval ) {
    // Nếu chênh lệch lớn hơn 0, cập nhật giá trị currentTime và trả về true
    *currentTime = currentMillis;
    return true;
  } else {
    // Ngược lại, trả về false
    return false;
  }
}