/**
 * https://www.youtube.com/watch?v=WMkN-uHd-Xo
 * Show different LED depending on the resistance of the LDR
 */
const int probePin = A1;
const int baud = 9600;
const int delayTime = 200;
const int pins[3] = {5, 3, 6};

void setup() {
  pinMode(probePin, INPUT);
  for(int i=0;i<3;i++){
    pinMode(pins[i], OUTPUT);
  }
  Serial.begin(baud);
}

void loop() {
  int intensity = analogRead(probePin);
  Serial.print("Intensity is ");
  Serial.println(intensity);
  float voltage = (5. / 1023.) * intensity;
  Serial.print("Voltage is ");
  Serial.println(voltage);

  if(voltage >4){
    light_led(2);
  } else if(voltage <3){
    light_led(0);
  } else {
    light_led(1);
  }
  delay(delayTime);
}

void light_led(int led_index){
  for(int i=0; i<3;i++){
    int pin = pins[i];
    if(i==led_index){
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  }
}
