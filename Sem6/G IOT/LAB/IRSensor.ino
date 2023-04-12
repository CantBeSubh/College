int LEDpin = 12;
int obstaclePin = 7;
int hasObstacle = LOW;  // LOW MEANS N O OBSTACLE

void setup() {
  pinMode(LEDpin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);
}
void loop() {
  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == HIGH) {
    Serial.println("Stop something is ahead!!");
    digitalWrite(LEDpin, HIGH);
  } else {
    Serial.println("Path is clear");
    digitalWrite(LEDpin, LOW);
  }
  delay(200);
}
