static int m1a = 2;
static int m1b = 3;
static int m2a = 4;
static int m2b = 7;

const int trigPin1 = 10;  //right
const int echoPin1 = 11;  //right 

const int trigPin2 = 8;   //left
const int echoPin2 = 9;   //left

const int trigPin3 = 12;   //front
const int echoPin3 = 13;   //front

const int pwm1 = 6; //pwm pins
const int pwm2 = 5;

boolean  flag = false;

double duration1, dist_r, duration2, dist_l, duration3, dist_f;
void setup() {
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2 , OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3 , OUTPUT);
  pinMode(echoPin3, INPUT);

  Serial.begin(9600);
}

void ultrasonic()
{
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  dist_r = (duration1 * .03430) / 2;
  Serial.print("dist_r: ");
  Serial.print (dist_r);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  dist_l = (duration2 * .03430) / 2;
  Serial.print("dist_l: ");
  Serial.println(dist_l);

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  dist_f = (duration3 * .03430) / 2;
  Serial.print("dist_f: ");
  Serial.println(dist_f);
}
void AI() {
  ultrasonic();


  if ( dist_f >= 22)
  {
    forwardpwm();

  }
  else if (dist_f < 22 && (dist_l + dist_r) > 15)
  {
    if (dist_l > dist_r)
    {
      leftpwm();

    }
    else {

      rightpwm();
    }

  }
  else {
    backwardpwm();
  }
}
void loop() {

  if (Serial.available() >= 0)
  {
    char bluetooth = Serial.read();
    switch (bluetooth)
    {
      case 'F':
        forward();

        break;
      case'B':
        backward();
        break;
      case'L':
        left();
        break;
      case'R':
        right();
        break;
      case'X':
        flag = true;
        break;
      case'x':
        flag = false;
        break;
      default:
        if (flag == true)
        {
          AI();
          break;
        }

        break;
    }
  }
}
void right() {
  Serial.println("right");
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  delay(30);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
}
void left() {
  Serial.println("left");
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);;
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
  delay(30);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
}
void forward() {
  Serial.println("Forward");
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
  delay(30);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);

}

void backward() {
  Serial.println("Back");
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  delay(30);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
}
void rightpwm() {
  Serial.println("rightpwm");
  analogWrite(pwm1, 150);
  analogWrite(pwm2, 150);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}
void leftpwm() {
  Serial.println("leftpwm");
  analogWrite(pwm1, 150);
  analogWrite(pwm2, 150);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);;
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
 
}
void forwardpwm() {
  Serial.println("Forwardpwm");
  analogWrite(pwm1, 150);
  analogWrite(pwm2, 150);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}
void backwardpwm() {
  Serial.println("Backpwm");
  analogWrite(pwm1, 150);
  analogWrite(pwm2, 150);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}
void wait() {
  Serial.println("Wait");
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}
