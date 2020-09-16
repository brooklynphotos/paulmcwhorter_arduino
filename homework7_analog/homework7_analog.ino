/**
 * increase brightness of LED
 * https://www.youtube.com/watch?v=6CRhpUV92ww
 */

int pin = 10;
int loopNumber = 0;
int steps = 2;

void setup(){
  pinMode(pin, OUTPUT);
}

void loop(){
  analogWrite(pin, loopNumber);
  loopNumber += steps;
  loopNumber %= 256;
  delay(50);
}
