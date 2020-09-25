/**
   https://www.youtube.com/watch?v=dHYKRrlPNzM
   Modulate the on/off at different frequencies of a passive buzzer
*/

const int buzzerPin = 7;
const int delayTime = 1;
const int potPin = A1;
const float maxWait = 10000.;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int potVal = analogRead(potPin);
  int wait = potVal * (maxWait / 1023);
  Serial.println(wait);
  if (wait > 0) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(wait);
    digitalWrite(buzzerPin, LOW);
  }
}
