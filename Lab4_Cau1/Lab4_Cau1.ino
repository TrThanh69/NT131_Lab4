// C++ code
//
int led[] = {12,2,3,4,5,6,7,8,9,10,11,13};
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 12; i++)
  	pinMode(led[i], OUTPUT);
}

void loop()
{
  int inputVal = analogRead(A0);
  int x = map(inputVal,0,1023,0,255);
  //Serial.println(inputVal);
  //delay(1000);
  // Dựa vào giả trị biến trở để bật dãy đèn dần dần 
  if (x  > 1)
  	digitalWrite(led[0], HIGH);
  else
    digitalWrite(led[0], LOW);
  if (x > 21)
    digitalWrite(led[1], HIGH);
  else
    digitalWrite(led[1], LOW);
  if (x > 42)
  	digitalWrite(led[2], HIGH);
  else 
    digitalWrite(led[2], LOW);
  if (x > 63)
  	digitalWrite(led[3], HIGH);
  else 
    digitalWrite(led[3], LOW);
  if (x > 84)
  	digitalWrite(led[4], HIGH);
  else 
    digitalWrite(led[4], LOW);
  if (x > 105)
  	digitalWrite(led[5], HIGH);
  else 
    digitalWrite(led[5], LOW);
  if (x > 126)
  	digitalWrite(led[6], HIGH);
  else 
    digitalWrite(led[6], LOW);
  if (x > 147)
  	digitalWrite(led[7], HIGH);
  else 
    digitalWrite(led[7], LOW);
  if (x > 168)
  	digitalWrite(led[8], HIGH);
  else 
    digitalWrite(led[8], LOW);
  if (x > 189 )
  	digitalWrite(led[9], HIGH);
  else 
    digitalWrite(led[9], LOW);
  if (x > 210)
  	digitalWrite(led[10], HIGH);
  else 
    digitalWrite(led[10], LOW);
  if (x > 231)
  	digitalWrite(led[11], HIGH);
  else 
    digitalWrite(led[11], LOW);
  
}