// Use this code to test your motor with the Arduino board:

// if you need PWM, just use the PWM outputs on the Arduino
// and instead of digitalWrite, you should use the analogWrite command

// —————————————————————————  Motors
int motor_left[] = {2, 3};
int motor_right[] = {7, 8};
const int trigPin1 = 10;
const int echoPin1 =11 ;
const int trigPin2=12;
const int echoPin2=13;
const int trigPin3=5;
const int echoPin3=9;

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}



// ————————————————————————— Setup
void setup() {
Serial.begin(9600);
int i;
for(i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);

}


}
// ————————————————————————— Loop
void loop() {


long duration1, inches1, cm1;
 long duration2, inches2, cm2;
 long duration3, inches3, cm3;

  
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);

  inches1 = microsecondsToInches(duration1);
  cm1 = microsecondsToCentimeters(duration1);



  pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

  inches2 = microsecondsToInches(duration2);
  cm2 = microsecondsToCentimeters(duration2);



  pinMode(trigPin3, OUTPUT);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  pinMode(echoPin3, INPUT);
  duration3 = pulseIn(echoPin3, HIGH);

  inches3 = microsecondsToInches(duration3);
  cm3 = microsecondsToCentimeters(duration3);

if(cm1>=20){
   

drive_forward();
//Serial.println(”1″);
}


else if (cm1 <= 20)

{
 motor_stop();
delay(500);
  
}

else if(cm2 <=20  )
{
 motor_stop();
delay(500);
  
  
}

}










// ————————————————————————— Drive

void motor_stop(){
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], LOW);
delay(1000);
}

void drive_forward(){
digitalWrite(motor_left[0], HIGH);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], HIGH);
digitalWrite(motor_right[1], LOW);
}


