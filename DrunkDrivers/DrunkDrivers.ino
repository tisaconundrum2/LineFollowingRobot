#include <Servo.h>
Servo leftServo;
Servo rightServo;
int isObstaclePin = 8;
int isObstacle = HIGH;

void setup() {
  leftServo.attach(9);
  rightServo.attach(10);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  runn();
//  test();
}

void runn() {
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW) {
    delay(20); // read yellow paper
    setAction(130, 0); // slight backward, forward
  } else {
    delay(20); // read black tape
    setAction(200, 165); // forward, slight backward
  }
}

void setAction(int leftSpeed, int rightSpeed) {
  leftServo.write(leftSpeed);
  rightServo.write(rightSpeed);
  Serial.print(leftSpeed);
  Serial.print(rightSpeed);
  Serial.println();
}

void test() {
  for (int pos = 0; pos <= 200; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    setAction(pos, 0);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 100ms for the servo to reach the position
  }
}
