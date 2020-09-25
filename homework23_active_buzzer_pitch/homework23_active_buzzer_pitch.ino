/**
 * https://www.youtube.com/watch?v=W5AApP9P-b0
 * Modulating the pitch to produce a different sound in active buzzer
 */

const int buzzerPin = 7;
const int delayTime = 1;
const int gap = 10;
const int potPin = A1;
const float maxWait = 100.;

void setup(){
  pinMode(buzzerPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  int potVal = analogRead(potPin);
  int wait = potVal * (maxWait / 1023);
  Serial.println(wait);
  digitalWrite(buzzerPin, HIGH);
  delay(wait);
  digitalWrite(buzzerPin, LOW);
}
