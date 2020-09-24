/**
 * https://www.youtube.com/watch?v=kj2br03bOuk
 * Mixing the RGB LED
 */

int redPin = 3;
int greenPin = 5;
int bluePin = 6;
int delayTime = 1;
int gap = 10;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  for(int b=0;b<256;b += gap){
    for(int g=0;g<256;g += gap){
      for(int r=0;r<256;r+= gap){
        digitalWrite(redPin, r);
        digitalWrite(greenPin, g);
        digitalWrite(bluePin, b);
        Serial.print("(");
        Serial.print(r);
        Serial.print(",");
        Serial.print(g);
        Serial.print(",");
        Serial.print(b);
        Serial.println(")");
        delay(delayTime);
      }
    }
  }
}
