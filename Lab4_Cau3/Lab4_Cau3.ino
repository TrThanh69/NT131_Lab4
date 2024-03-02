void setup() 
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode (3, OUTPUT);
}
 
void loop() 
{

  int value = analogRead(A0);     // Ta sẽ đọc giá trị hiệu điện thế của cảm biến
                                  // Giá trị được số hóa thành 1 số nguyên có giá trị
                                  // trong khoảng từ 0 đến 100                  
  int doAm =(map(value, 0, 876, 0, 100));
  if (doAm <= 40)
    digitalWrite(3,HIGH);
  else
    digitalWrite(3,LOW);
  Serial.print(doAm);
  Serial.println("%");
}