/**
 * https://www.youtube.com/watch?v=nPOKOi1jIK0
 * Create three LEDs: r g b
 * Red: 5x fast
 * Green: 10x slow
 * Blue: 15x really slow
 */

int loopCount = 0;
int MAX_LOOP = 15;
int bluePin = 9;
int greenPin = 8;
int redPin = 11;
int interval = 200;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  if(loopCount>MAX_LOOP){
    loopCount = 0;
  }
  blink_led(redPin, 5);
  if((loopCount % 10) == 0){
    blink_led(greenPin, 1);
  }
  if((loopCount % 15) == 0){
    blink_led(bluePin, 1);
  }
  loopCount++;
}

void blink_led(int pin, int count){
  int index;
  for(index = 0; index < count; index++) {
    digitalWrite(pin, HIGH);   // Turn on the LED
    delay(interval);              // Wait for one second
    digitalWrite(pin, LOW);    // Turn off the LED  
    delay(interval);              // Wait for one second
  }
}
