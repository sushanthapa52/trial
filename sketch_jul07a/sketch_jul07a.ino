
int brightness=5;
int fadeAmount=5;

void setup() {
 pinMode(9,OUTPUT);

 // put your setup code here, to run once:

}

void loop() {
analogWrite(9,brightness);
brightness=brightness+fadeAmount;
if (brightness<=0||brightness>=255);
{
fadeAmount=-fadeAmount;
}
delay(5000);
}
