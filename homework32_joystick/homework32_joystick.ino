/**
 * https://www.youtube.com/watch?v=B6YEQj4d5WU
 * Use joystick to control LEDs
 */

#include <Servo.h>

const int baud = 9600;
const int delayTime = 200;
const int servoPin = 7;
int servoPosition = 0; // where it is now
// virtual object for servo
Servo servo;
// joystick pins
const int joystickXPin = A2;
const int joystickYPin = A3;
const int joystickSwitchPin = 12;
// led
const int redPin = 3;
const int yellowPin = 6;
const int greenPin = 5;

void setup() {
  pinMode(joystickXPin, INPUT);
  pinMode(joystickYPin, INPUT);
  pinMode(joystickSwitchPin, INPUT);
  digitalWrite(joystickSwitchPin, HIGH);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  Serial.begin(baud);
//  servo.attach(servoPin); 
}

void loop() {
//  servo.write(servoPosition);
  int switchValue = digitalRead(joystickSwitchPin);
  int xValue = analogRead(joystickXPin);
  int yValue = analogRead(joystickYPin);
  digitalWrite(redPin, switchValue);
  analogWrite(greenPin, xValue * (255. / 1023));
  analogWrite(yellowPin, yValue * (255. / 1023));
  Serial.print("("+String(xValue)+","+String(yValue)+","+String(switchValue)+")");
  Serial.print("servo position is ");
  Serial.println(servoPosition);
  delay(delayTime);

}
