const int lm1=8;
const int lm2=9;
const int rm1=10;
const int rm2=11;
const int en1=5;
const int en2=6;

char bt;
void setup()
{
  pinMode(lm1,OUTPUT); 
  pinMode(lm2,OUTPUT); 
  pinMode(rm1,OUTPUT); 
  pinMode(rm2,OUTPUT); 
  Serial.begin(9600);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
 
}

void loop()
 {
    if (Serial.available()>=0)
   {
    char bt=Serial.read();
    Serial.println(bt);
    
    switch(bt)
     {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      default: wait();break;
      }
      
   }
} 
void left()
{Serial.println("left");
  analogWrite(en1,255);
  analogWrite(en2,255);
  digitalWrite(lm1,HIGH);
   digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
   digitalWrite(rm2,LOW);
  
}
void right()
{  Serial.println("right");
   analogWrite(en1,255);
   analogWrite(en2,255);
   Serial.println("back");
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,HIGH);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,HIGH);
    
}

 void forward()
 {  Serial.println("forward");
   analogWrite(en1,250 );
   analogWrite(en2,255);
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,HIGH);
   digitalWrite(rm1,HIGH);
   digitalWrite(rm2,LOW);
 
 }
 void backward()
 {  Serial.println("backward");
   analogWrite(en1,255);
   analogWrite(en2,250);
   digitalWrite(lm1,HIGH);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,HIGH);
 }
 void wait()
 {
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,LOW);
 }
 

