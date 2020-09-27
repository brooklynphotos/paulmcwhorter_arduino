/**
 * https://www.youtube.com/watch?v=XWL6Ydsmi0s
 * Two push buttons, one to increase brightness of LED, the other to decrease
 * If reaching the end of either, buzzer goes off
 */
#define UP 1
#define DOWN 0

const int dimmerProbePin = 7;
const int brighterProbePin = 2;
const int baud = 9600;
const int delayTime = 200;
const int ledPin = 3;
bool lastRead = UP; // button is naturally not pushed
int ledState = 120;
const int delta = 8;
const int buzzerPin = 12;

void setup() {
  pinMode(dimmerProbePin, INPUT);
  pinMode(brighterProbePin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  analogWrite(ledPin, ledState);
  beep();
  Serial.begin(baud);
}

void loop() {
  if(digitalRead(dimmerProbePin)==DOWN){
    changeLed(-delta);
  }
  if(digitalRead(brighterProbePin)==DOWN){
    changeLed(delta);
  }
  Serial.println(ledState);
  delay(delayTime);
}

void beep() {
  digitalWrite(buzzerPin, HIGH);
  delay(delayTime);
  digitalWrite(buzzerPin, LOW);
}

void changeLed(int change){
  int newState = ledState + change;
  if(newState<255 && newState >=0){
    analogWrite(ledPin, newState);
    ledState = newState;
  }else{
    beep();
    Serial.println("out of bound");
  }
}
