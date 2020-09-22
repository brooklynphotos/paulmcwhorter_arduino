/**
 * https://www.youtube.com/watch?v=7wKdxsvXAFo&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=15&t=0s
 * resistance changes correspond to LED brightness
 */

int probePin = A1;
int ledPin = 3;
int blinkDelay = 1000;
void setup(){
  pinMode(probePin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  int intensity = analogRead(probePin);
  light_led(intensity);
}

void light_led(int intensity){
  int amount = intensity * (255. / 1023.);
   analogWrite(ledPin, amount);
}
