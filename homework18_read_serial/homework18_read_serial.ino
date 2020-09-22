/**
 * https://www.youtube.com/watch?v=7aP5KL5clWA&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=18
 * Ask user how many times to blink an LED
 */

int ledPin = 4;
int blinkDelay = 1000;
String msg = "Blink rate please";
int baudRate = 9600;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(baudRate);
}

void loop(){
  Serial.println(msg);
  while(Serial.available() == 0){}
  int blinkCount = Serial.parseInt();
  blink_led(blinkCount);
}

void blink_led(int times){
  for(int i=0;i<times;i++){
      digitalWrite(ledPin, HIGH);
      delay(blinkDelay);
      digitalWrite(ledPin, LOW);
      delay(blinkDelay);
  }
}
