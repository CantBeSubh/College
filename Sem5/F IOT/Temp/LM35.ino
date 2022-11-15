/*  Program to get data from lm35 temperature sensor on analog pin
 *  by: Stephan Ofosuhene
 */

int tempSensor = A0;

void setup()
{
    // open serial port
    Serial.begin(9600);
}

void loop()
{
    // print sensor readings to the serial output
    Serial.println(get_temp(tempSensor));
    analogReference(INTERNAL);
}

float get_temp(int sensorPin)
{
    float temp = analogRead(sensorPin);
    temp = (temp * 5000.0) / 1024;
    return temp;
}