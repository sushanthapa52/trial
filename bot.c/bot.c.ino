#define m1a 12
#define m1b 11
#define m2a 9
#define m2b 10
#define trigpin 8
#define echopin 7
long duration,distance;
void setup()
{
  Serial.begin(9600);
  pinMode(m1a,OUTPUT);
  pinMode(m1b,OUTPUT);
  pinMode(m2a,OUTPUT);
  pinMode(m2b,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  }

void sensor()
{ 
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echopin,HIGH);
  distance=(duration/2)/29.1;
  Serial.print(distance);
  Serial.print("cm");
 }

void forward()
{
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);
 }
void backward()
{
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,HIGH);
}
void right()
{
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,HIGH);
}
void left()
{ digitalWrite(m1a,HIGH);
 digitalWrite(m1b,LOW);
 digitalWrite(m2a,HIGH);
 digitalWrite(m2b,LOW);
}  
void loop()
{
  sensor();
     {
    if(distance<=5)
     {
      backward();
      delay(5000);
      right();
      delay(3000);
      }
     else
     {forward();
     }
 }
 }
