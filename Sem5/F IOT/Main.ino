// the setup function runs once when you press reset or power the board
void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(100);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    delay(100);                      // wait for a second
}

// int tempSensor = A0;

// void setup()
// {
//     // open serial port
//     Serial.begin(9600);
// }

// void loop()
// {
//     // print sensor readings to the serial output
//     Serial.println(get_temp(tempSensor));
//     analogReference(INTERNAL);
// }

// float get_temp(int sensorPin)
// {
//     float temp = analogRead(sensorPin);
//     temp = (temp * 5000.0) / 1024;
//     return temp;
// }