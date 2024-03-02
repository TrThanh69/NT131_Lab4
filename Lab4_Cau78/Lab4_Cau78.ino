#include <Wire.h>
#include <DHT.h>
#include <BH1750.h>

BH1750 lightMeter;
const int dhtPin = 2; // gán chân đọc tín hiệu là chân 6
const int dhtType = DHT22;  // chọn loại DHT

DHT dht( dhtPin,dhtType);

void setup(){

  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));
  Serial.println("Test DHT22");
  dht.begin();

}

void loop() {

  // Đo ánh sáng ~ Câu 4
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);

  float h = dht.readHumidity(); // đọc độ ẩm
  float t = dht.readTemperature(); // đọc nhiệt độ

  // Hiển thị trên Serial
  Serial.print(" Nhiệt độ : "); Serial.print(t); Serial.println(" *C ");
  Serial.print(" Độ ẩm : ");Serial.print(h); Serial.println(" % ");
  Serial.println(" ");
  delay(500);
}