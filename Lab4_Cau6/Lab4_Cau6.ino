// C++ code
//
#include <Servo.h>
Servo servo; // khởi tạo đối tượng servo với tên gọi là servo
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT); 
  servo.attach(6); //  attach (đính) servo ở chân digital/analog 6/A2 
  servo.write(0);// quay Servo về 0º
}

void loop()
{
  
  int value = digitalRead(2); //đọc giá trị cảm biến lửa
  Serial.println(value);
  if (value == 0) // Phát hiện lửa -> value = 0 
  {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);

    //Servo sẽ quay 1 góc 90 độ 
    servo.write(0);
    delay(1000);
    servo.write(90);
    delay(1000);
  }
}