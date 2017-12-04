#include <Servo.h>
Servo leftServo;
Servo rightServo;


void setup() {
  leftServo.attach(9); //Pin 9 for Servo Output
  rightServo.attach(10); // Pin 10 for Servo Output
}

void loop() {
  
}

void leftFoward(){
  leftServo.write(135);
}

void leftbackward(){
  leftServo.write(45);  
}

void rightFoward(){
  rightServo.write(135);
}

void rightBackward(){
  rightServo.write(45);
}

