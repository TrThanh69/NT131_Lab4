int trig = 11, echo = 10;
int led[] = {13,12,9,8,7,6,5,4,3,2};
float distance;
void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  for(int i =0; i < 10; i++)
  	pinMode(led[i], OUTPUT);
  Serial.begin(9600);
}
float getDistance() // Thiết lập khoảng cách đo 
{
  digitalWrite(trig, HIGH); // Đặt chân kích hoạt (trigger) lên mức HIGH
  //delayMicroseconds(5);
  digitalWrite(trig,LOW); // Đặt chân kích hoạt về mức LOW
  int timer = pulseIn(echo, HIGH); // Đo độ rộng xung trên chân echo
  return timer/58.3f; // Chuyển đổi độ rộng xung thành khoảng cách theo đơn vị centimet và trả về kết quả
} 
void loop()
{
  distance = getDistance();
  delay(1000);
  Serial.println(distance);
  // Khoảng cách vật thể càng gần thì sẽ mở nhiều bóng 
  if(distance < 13)
    digitalWrite(led[0], HIGH);
  else
   digitalWrite(led[0], LOW);
   if(distance < 12)
    digitalWrite(led[1], HIGH);
  else
   digitalWrite(led[1], LOW);
  if(distance < 11)
    digitalWrite(led[2], HIGH);
  else
   digitalWrite(led[2], LOW);
  if(distance < 10)
    digitalWrite(led[3], HIGH);
  else
   digitalWrite(led[3], LOW);
  if(distance < 9)
    digitalWrite(led[4], HIGH);
  else
   digitalWrite(led[4], LOW);
  if(distance < 8)
    digitalWrite(led[5], HIGH);
  else
   digitalWrite(led[5], LOW);
  if(distance < 7)
    digitalWrite(led[6], HIGH);
  else
   digitalWrite(led[6], LOW);
  if(distance < 6)
    digitalWrite(led[7], HIGH);
  else
   digitalWrite(led[7], LOW);
  if(distance < 5)
    digitalWrite(led[8], HIGH);
  else
   digitalWrite(led[8], LOW);
  if(distance < 4)
    digitalWrite(led[9], HIGH);
  else
   digitalWrite(led[9], LOW);
  if(distance < 3)
    digitalWrite(led[10], HIGH);
  else
   digitalWrite(led[10], LOW);
}