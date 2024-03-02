#include <Wire.h>
#include <BH1750.h> // Cài đặt thư viện BH1750

BH1750 lightMeter;

void setup(){
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  Wire.begin(); // Khởi động Wire 

  lightMeter.begin(); //khởi động cảm biến BH1750

  Serial.println(F("BH1750 Test begin"));
}

void loop() 
{
  float lux = lightMeter.readLightLevel(); // Đọc giá trị từ cảm biến đo cường độ ánh sáng 
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  // Kiểm tra sáng/tối bằng cách đặt giá trị tối < 1
    if(lux < 1)
  	digitalWrite(3, HIGH);
  else
  	digitalWrite(3, LOW);
  delay(1000);
}