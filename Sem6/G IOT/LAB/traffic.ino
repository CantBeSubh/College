// variables
int GREEN = 2;
int YELLOW = 3;
int RED = 4;

int DELAY GREEN = 1000;
int DELAY YELLOW = 500;
int DELAY_RED = 1000;
void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  green_light();
  delay(DELAY_GREEN);
  yellow_light();
  delay(DELAY YELLOW);
  red_light();
  delay(DELAY_RED);
}

void green_light() {
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}
void yellow_light() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}
void red light() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}