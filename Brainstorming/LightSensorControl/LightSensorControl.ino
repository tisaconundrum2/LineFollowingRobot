int LED = 13; // Use the onboard Uno LED
int isObstaclePin = 7; // This is our input pin
int isObstacle = HIGH; // HIGH MEANS NO OBSTACLE

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(isObstaclePin, INPUT);
    Serial.begin(9600);
}

void loop() {
    isObstacle = digitalRead(isObstaclePin);
    if (isObstacle == LOW) {
        Serial.println("Yellow");
        digitalWrite(LED, HIGH);
    } else {
        Serial.println("Black");
        digitalWrite(LED, LOW);
    }
    delay(200);
}

//const int FAST = 20;
//const int SLOW = 10;
//const int STOP = 90;
//int FASTFORWARD = STOP + FAST;
//int FASTBACKWARD = STOP - FAST;
//
//int SLOWFORWARD = STOP + SLOW;
//int SLOWBACKWARD = STOP - SLOW;

