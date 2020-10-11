/**
 * https://toptechboy.com/arduino-tutorial-42-understanding-how-to-use-a-serial-to-parallel-shift-register-74hc595/
 * increment the bit LEDs
 */

const int baud = 9600;
const int latchPin = 11; // latch from pin 12
const int clockPin = 9; // from pin 11
const int serialInputPin = 12; // from pin 14
const int delayTime = 500;

byte bits = 0x00;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(serialInputPin, OUTPUT);
  Serial.begin(baud);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(serialInputPin, clockPin, MSBFIRST, bits);
  digitalWrite(latchPin, HIGH);
  Serial.println(bits, BIN);
  delay(delayTime);
  bits++;
  bits %= 0xFF;
}
