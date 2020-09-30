/**
 * https://www.youtube.com/watch?v=aFHu65LiFok
 * Use the servo motor to indicate brightness of light shone on the photo resistor
 * 
 * Notes:
 * LDR needs 5K resistor to create a voltage
 */

#include <Servo.h>

const int probePin = A1;
const int baud = 9600;
const int delayTime = 200;
const int servoPin = 7;
int servoPosition = 0; // where it is now
// virtual object for servo
Servo servo;

void setup() {
  Serial.begin(baud);
  servo.attach(servoPin); 
}

void loop() {
  servo.write(servoPosition);
  int intensity = analogRead(probePin);
  servoPosition = intensity * (180. / 1024);
  servo.write(servoPosition);
  Serial.print("servo position is ");
  Serial.println(servoPosition);
  delay(delayTime);

}
