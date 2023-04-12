void primeFactors(int n);
void primeFactors(int n) {
  while (n % 2 == 0) {
    Serial.println(2);
    n /= 2;
  }

  for (int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      Serial.println(String(i));
      n /= i;
    }
  }
  if (n > 2) Serial.println(String(n));
}

void setup() {
  Serial.begin(9600);
  int n = 315;
  primeFactors(n);
}
void loop() {
}