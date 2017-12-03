#include <Servo.h>

Servo leftServo;
Servo rightServo;

int isObstaclePin = 8;
int isObstacle = HIGH;
const int FAST = 30;
const int SLOW = 10;
const int STOP = 0;

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
    delay(20); // read yellow
    setAction(130, 0); // slight down, up
  } else {
    delay(20); // read black
    setAction(200, 165); // up, slight down
  }
}

void test() {
  for (int pos = 0; pos <= 200; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    setAction(pos, 0);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
}

void setAction(int leftSpeed, int rightSpeed) {
  leftServo.write(leftSpeed);
  rightServo.write(rightSpeed);
  Serial.print(leftSpeed);
  Serial.print(rightSpeed);
  Serial.println();
}
