#define tp 7
#define ep 8
#define l1 9
#define l2 10 
 long int distance;
 long int time;
void setup()
   {Serial.begin(9600);
               pinMode(tp,OUTPUT);
              pinMode(ep,INPUT);
               pinMode(l1,OUTPUT);
               pinMode(l2,OUTPUT);
 }
 void loop()
 {
       digitalWrite(tp,LOW);
       delay(10);
       digitalWrite(tp,HIGH);
       time=pulseIn(ep,HIGH);
       distance=(time/2)/29.1;
       Serial.print(distance);
       Serial.println("cm");
        {if (distance<=10)
          digitalWrite(l1,HIGH);
         else
         digitalWrite(l2,HIGH);
        }
 }
