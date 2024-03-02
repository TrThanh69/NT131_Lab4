// C++ code
//
int led[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
int speed = 1000;
int point = 0;
int flagTN;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT_PULLUP);
  for (int i = 0; i <= 12; i++)
    pinMode(led[i], OUTPUT);
}

void loop()
{
  if(check() == true)
  {
    int notify = light(speed);  // Gọi hàm light() với tham số là speed và lưu kết quả vào biến notify
    if ((notify == 7 && flagTN == 1) || (notify == 5 && flagTN == 0)) // Nếu các điều kiện cụ thể được đáp ứng
  {
    {
      speed-=100; // Giảm tốc độ điều khiển đi 100 đơn v
      point+=1;  // Tăng điểm lên 1 đơn vị
      Serial.println("Tang toc do"); // In ra "Tăng tốc độ" trên Serial Monitor
      Serial.print("Diem cua ban la :"); // In ra "Điểm của bạn là:" trên Serial Monitor
      Serial.println(point);  // In ra giá trị hiện tại của điểm trên Serial Monitor
    }
    else // Nếu các điều kiện không được đáp ứng
    {
      speed+=100; // Tăng tốc độ điều khiển lên 100 đơn vị
      if (point > 0)  // Nếu điểm lớn hơn 0
        point-=1; // Giảm điểm xuống 1 đơn vị 
      Serial.println("Giam toc do"); // In ra "Giảm tốc độ" trên Serial Monitor
      Serial.print("Diem cua ban la :"); // In ra "Điểm của bạn là:" trên Serial Monitor
      Serial.println(point); // In ra giá trị hiện tại của điểm trên Serial Monitor
    }
  } 
}
int light(int x)
{
  int i;
  bool flag = true;
  // Bật các LED từ 0 đến 12
  for(i=0; i < 13; i++)
  {
    flag = check(); // Kiểm tra điều kiện bên trong hàm check()
    if (flag == false) // Nếu điều kiện không được đáp ứng
    {
      flagTN = 1; // Gán giá trị cho biến flagTN
      return i; // Trả về giá trị i
    }
    digitalWrite(led[i], HIGH); // Bật LED thứ i
    delay(x); // Tạm dừng theo thời gian x
    digitalWrite(led[i], LOW); // Tắt LED thứ i
  }
  // Tắt các LED từ 12 đến 1
  for(i=12; i > 0; i--)
  {
    flag = check(); // Kiểm tra điều kiện bên trong hàm check()
    if (flag == false) // Nếu điều kiện không được đáp ứng
    {
      flagTN=0;  // Gán giá trị cho biến flagTN
      return i;  // Trả về giá trị i
    }
    digitalWrite(led[i], HIGH); // Bật LED thứ i
    delay(x);  // Tạm dừng theo thời gian x
    digitalWrite(led[i], LOW); // Tắt LED thứ i
  }
  return 1; // Trả về giá trị 1 nếu không có điều kiện nào được đáp ứng
}
bool check()
{
  if(digitalRead(A0) == 0)
    return false;
  return true;
}