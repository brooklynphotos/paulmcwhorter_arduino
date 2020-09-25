/**
 * https://www.youtube.com/watch?v=tuRAvlVBEl0
 * Raise the buzzer when above 1000 from potentiometer, for lower values, light up the LEDs
 */

const int pins[4] = {5, 3, 6, 7};
const int delayTime = 100;
const int buzzerPin = pins[3];
const int potPin = A1;

void setup(){
  for(int i=0;i<4;i++){
    pinMode(pins[i], OUTPUT);
  }
  // just to test
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  Serial.begin(9600);
}

void loop(){
  int potRead = analogRead(potPin);
  if(potRead < 300){
    set_status(0);
  }
  else if(potRead >=300 && potRead <600){
    set_status(1);
  }
  else if(potRead >=600 && potRead <1000){
    set_status(2);
  }
  else {
    set_status(3);
  }
  Serial.println(potRead);
  delay(delayTime);
}

void set_status(int index){
  for(int i=0;i<4;i++){
    if(i==index){
      digitalWrite(pins[i], HIGH);
    }else{
      digitalWrite(pins[i], LOW);
    }
  }
}
