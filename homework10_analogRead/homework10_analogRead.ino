/**
 * read voltage from the circuit via a probe
 * https://www.youtube.com/watch?v=5TitZmA66bI
 */

int inputPin = A1;
float voltage = 0;
int delayTime = 500;
int baud = 9600;

void setup(){
  pinMode(inputPin, INPUT);
  Serial.begin(baud);
}

void loop(){
  int intensity = analogRead(inputPin);
  voltage = intensity * (5. / 1024.);
  Serial.println(voltage);
  delay(delayTime);
}
