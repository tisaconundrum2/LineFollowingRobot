#include <Servo.h>

// ------ Servo init -------
// 45-90-135
Servo leftServo;
Servo rightServo;

// ------ LED init -------
int isObstaclePin = 8; // This is our input pin
int isObstacle = HIGH; // HIGH MEANS NO OBSTACLE

int high = 20;
int slow = 10;

int above = 90 + high;
int below = 90 - high;

int slowAbove = 90 + slow;
int slowBelow = 90 - slow;

int Stop = 90;

void setup() {
  leftServo.attach(9);            //Pin 9 for Servo Output
  rightServo.attach(10);          // Pin 10 for Servo Output
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  //
  // if line
  //  rightForward()  
  //  leftSlow()
  // if no line
  //  rightSlow()
  //  leftFoward()
  //
  //
  //
  if (isObstacle == LOW) {
    leftStop();
    rightForward();
  } else {
    rightStop();
    leftForward();
  }
}

void leftForward(){leftServo.write(above);}
void rightForward(){rightServo.write(below);}

void leftbackward(){leftServo.write(below);  }
void rightBackward(){rightServo.write(above);}

void leftStop(){leftServo.write(Stop);}
void rightStop(){rightServo.write(Stop);}

void leftSlow(){leftServo.write(slowAbove);}
void rightSlow(){rightServo.write(slowBelow);}
