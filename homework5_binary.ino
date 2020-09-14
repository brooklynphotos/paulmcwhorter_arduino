/* 
 * https://www.youtube.com/watch?v=rTuKKVcYeMg
 * create LEDs that will count from 0 to 15 in binary format
 */

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);   // Turn on the LED
  delay(1000);              // Wait for one second
  digitalWrite(13, LOW);    // Turn off the LED  
  delay(1000);              // Wait for one second
}