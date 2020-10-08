/**
 * https://toptechboy.com/arduino-tutorial-39-using-a-joystick-to-control-dc-motor-speed-and-direction/
 * Use DC motor with a joystick
 */

const int baud = 9600;
int motSpeed = 2; // in RPM from 2 to 19
const int xPin = A0;
const int driverPin = 9;
const int dirPin1 = 8;
const int dirPin2 = 12;

const float neutralValue = 518.;

const int delayTime = 200;
int minSpeed = 80;

void setup() {
  pinMode(xPin, INPUT);
  pinMode(driverPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  Serial.begin(baud);
}

void loop() {
  int xVal = analogRead(xPin);
  Serial.println("Button: "+String(xVal));
  runMotor(xVal - neutralValue);
//  runMotorX(true);
  delay(delayTime);
}

void runMotorX(boolean on) {
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, on ? LOW : HIGH);
  analogWrite(driverPin, 255);
  
}

void runMotor(int velocity) {
  Serial.println("Velocity: "+String(velocity));
  if(velocity>0){
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
  } else if(velocity<0){
    digitalWrite(dirPin2, HIGH);
    digitalWrite(dirPin1, LOW);
  } else {
    digitalWrite(dirPin2, LOW);
    digitalWrite(dirPin1, LOW);
  }
  int driveValue = velocity==0 ? 0 : max(minSpeed, abs(velocity * (255. / neutralValue)));
  Serial.println("Drive value: "+String(driveValue));
  analogWrite(driverPin, driveValue);
  
}
