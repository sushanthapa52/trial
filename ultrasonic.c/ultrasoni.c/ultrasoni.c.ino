int trigPin = 7;
int echoPin = 8;
int led1 = 9;
int led2 = 10;


void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led2, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance );
  Serial.println("cm"); 
 

  if ((distance <= 50&&distance>30))
  
   { digitalWrite(led1, HIGH);
     digitalWrite(led2, LOW);
   }
    if(distance>=5&&distance<30)
     {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
    
      }

 
}

