/**
 * https://www.youtube.com/watch?v=CfdaJ4z4u4w
 * Have three LEDs: red, green, and blue
 * Red: blink 5 times
 * Green: 10 times
 * Blue: 15 times
 *
 */
int interval = 500;
int colorDelay = 2000;
int bluePin = 9;
int greenPin = 8;
int redPin = 11;
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  blink_led(redPin, 5);
  delay(colorDelay);
  blink_led(greenPin, 10);
  delay(colorDelay);
  blink_led(bluePin, 15);
  delay(colorDelay);
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
