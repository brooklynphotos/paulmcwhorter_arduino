/**
 * potentiameter reading and turning on LEDs for certain values
 * https://www.youtube.com/watch?v=ORNted-NgRM
 */
int probePin = A1;
int baud = 9600;
int delayTime = 200;

void setup() {
  pinMode(probePin, INPUT);
  Serial.begin(baud);
}

void loop() {
  int intensity = analogRead(probePin);
  float voltage = (5. / 1023.) * intensity;
  Serial.print("Voltage is ");
  Serial.println(voltage);
  delay(delayTime);
}
