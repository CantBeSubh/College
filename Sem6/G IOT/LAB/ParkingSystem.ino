int LEDpin = 13;
int obstaclePin = 7;
int hasObstacle = LOW;

const int trigPin = 9;
const int echoPin = 10;

const int motorPin1  = 5;  
const int motorPin2  = 6;

int gate = 0; //0 is closed 1 is open
int parking = 0; //0 is empty and 1 is parked

long duration;
int distance;
void gate_close(){
  Serial.println("Gate Closed");
  gate = 0;
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(2000);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void gate_open(){
  Serial.println("Gate Opened");
  gate = 1; 
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(2000);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}


void setup() {
  pinMode(LEDpin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  
  Serial.begin(9600);
}
void loop() {
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration * 0.034/2;
  Serial.print("Distance");
  Serial.println(distance);

  
  if (distance<10) {
    if(gate!=1){
      Serial.println("Car arrived");
      gate_open();
    }
  }
  else
  {
    if(gate==1){
      gate_close();
    }
  }
  hasObstacle = digitalRead(obstaclePin);
  
  if (hasObstacle == LOW) {
    if(parking!=1){
      parking = 1;
      gate_close();
      Serial.println("Car is Parked");
      digitalWrite(LEDpin, HIGH);
    }
  }   
  else{
    digitalWrite(LEDpin, LOW);
    parking = 0;
  }   
  
  delay(2000);
}
