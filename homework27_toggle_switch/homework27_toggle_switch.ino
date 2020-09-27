/**
 * https://www.youtube.com/watch?v=AgQW81zzR18
 * Pushbuton toggles the LED
 */
#define UP 1
#define DOWN 0

const int probePin = 7;
const int baud = 9600;
const int delayTime = 200;
const int ledPin = 3;
bool lastRead = UP; // button is naturally not pushed
bool ledState = false;

void setup() {
  pinMode(probePin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(baud);
}

void loop() {
  int reading = digitalRead(probePin);
  Serial.println(reading);

  // button just released
  if(reading==UP && lastRead==DOWN){
    toggleLed();
  }
  lastRead = reading;
  delay(delayTime);
}

void toggleLed(){
  ledState = !ledState;
  if(ledState){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}
