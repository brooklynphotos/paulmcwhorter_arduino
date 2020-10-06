/**
 * https://www.youtube.com/watch?v=B6YEQj4d5WU
 * Use stepper motor with button
 */

#include <Stepper.h>
#define UP 1
#define DOWN 0

const int baud = 9600;
const int stepsPR = 2048;
int motSpeed = 2; // in RPM from 2 to 19
Stepper stepper(stepsPR, 8, 10, 9, 11);
const int buttonPin = 2;
int prevButtonState = UP;
const int delayTime = 200;
int motDir = 1;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(baud);
  stepper.setSpeed(motSpeed);
}

void loop() {
  int buttonVal = digitalRead(buttonPin);
  if(prevButtonState==DOWN && buttonVal==UP){
    motDir *= -1;
  }
  prevButtonState = buttonVal;
  Serial.println("Button: "+String(buttonVal));
  stepper.step(motDir * 50);
//  delay(delayTime);
}
