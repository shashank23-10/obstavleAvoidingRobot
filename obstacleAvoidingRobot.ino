#include<Servo.h>
Servo mymotor;

#define motor1a 2 
#define motor1b 3
#define motor2a 4
#define motor2b 5
  
#define trig 6
#define echo 7

void setup()
{
  Serial.begin(9600);
  
  mymotor.attach(8);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
 
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
}

void forward(){
  digitalWrite(motor1a, HIGH);
  digitalWrite(motor1b, LOW);
    
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
}
void backward(){
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, HIGH);
    
  digitalWrite(motor2a, LOW);
  digitalWrite(motor2b, HIGH);
}
void left(){
  digitalWrite(motor1a, HIGH);
  digitalWrite(motor1b, LOW);
    
  digitalWrite(motor2a, LOW);
  digitalWrite(motor2b, HIGH);
}
void right(){
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, HIGH);
    
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
}
void stop(){
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, LOW);
    
  digitalWrite(motor2a, LOW);
  digitalWrite(motor2b, LOW);
}
void loop()
{
  digitalWrite(trig, LOW);
  delay(1000); 
  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);
  
  float dist = pulseIn(echo, HIGH);
  float distance = dist*0.3433/20;
      //formula to convert garbage to cm
    Serial.println(distance);
  
  if(distance>50)
  {
    mymotor.write(0);
    forward();
  }
  else{
    backward();
    delay(1000);
    mymotor.write(120);
    delay(1000);
    mymotor.write(30);
    delay(1000);
    left();
    delay(1000);
    right();
  }

}

