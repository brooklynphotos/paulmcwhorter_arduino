/**
 * potentiameter reading and turning on three LEDs for certain values
 * https://www.youtube.com/watch?v=ORNted-NgRM
 */
int probePin = A1;
int baud = 9600;
int delayTime = 200;
int pins[3] = {2, 3, 4};

void setup() {
  pinMode(probePin, INPUT);
  for(int i=0;i<3;i++){
    pinMode(pins[i], OUTPUT);
  }
  Serial.begin(baud);
}

void loop() {
  int intensity = analogRead(probePin);
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
