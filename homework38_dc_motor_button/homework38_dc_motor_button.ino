/**
 * https://toptechboy.com/arduino-tutorial-38-using-a-tilt-switch-cut-off-with-a-dc-motor/
 * Use DC motor with button
 */
#define UP 1
#define DOWN 0

const int baud = 9600;
const int stepsPR = 2048;
int motSpeed = 2; // in RPM from 2 to 19
const int buttonPin = 2;
const int driverPin = 9;
const int dirPin1 = 8;
const int dirPin2 = 12;

const int delayTime = 200;
int motDir = 1;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(driverPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  Serial.begin(baud);
}

void loop() {
  int buttonVal = digitalRead(buttonPin);
  Serial.println("Button: "+String(buttonVal));
  runMotor(buttonVal==DOWN);
  delay(delayTime);
}

void runMotor(boolean on) {
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, on ? LOW : HIGH);
  analogWrite(driverPin, 255);
  
}
