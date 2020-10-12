/**
 * https://toptechboy.com/arduino-tutorial-42-understanding-how-to-use-a-serial-to-parallel-shift-register-74hc595/
 * Also all lessons after that for the shift register
 * There are a few buttons to change the mode
 * 1. increment the bit LEDs
 * 2. Shift left
 * 3. Shift Left cyclic
 * 4. Flip the bits
 * They all have the same schematic
 */

#define INCREMENT 0
#define SHIFT_LEFT 1
#define SHIFT_LEFT_CYCLIC 2
#define FLIP 3

#define UP 0
#define DOWN 1

const int baud = 9600;
const int latchPin = 11; // latch from pin 12
const int clockPin = 9; // from pin 11
const int serialInputPin = 12; // from pin 14
const int delayTime = 500;

// button pins
const int controlButton = 2;
int currentButtonState = DOWN;
byte currentCommand = INCREMENT; 

byte bits = 0x00;

void setup() {
  pinMode(controlButton, INPUT_PULLUP);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(serialInputPin, OUTPUT);
  Serial.begin(baud);
}

void loop() {
  if(buttonIsPushed()){
    ++currentCommand;
    currentCommand %= 4;
    Serial.println("Button pushed to "+String(currentCommand));
  }
  switch(currentCommand){
    case INCREMENT:
      increment();
      break;
    case SHIFT_LEFT:
      shiftLeft();
      break;
    case SHIFT_LEFT_CYCLIC:
      shiftLeftCyclic();
      break;
    case FLIP:
      flip();
      break;
  }
  displayBits();
  delay(delayTime);
}

bool buttonIsPushed(){
  int newState = digitalRead(controlButton);
  bool res = currentButtonState==DOWN && newState==UP;
  currentButtonState = newState;
  return res;
}

void shiftLeft(){
  bits <<= 1;
  Serial.println("shift left for "+String(bits, BIN));
}
void shiftLeftCyclic(){
  bits = (bits >> 7) + (bits << 1);
  Serial.println("shift left cyclic for "+String(bits, BIN));
}
void flip(){
  Serial.println("flip for "+String(bits, BIN));
  bits = ~bits;
}
void increment(){
  Serial.println("Increment for "+String(bits, BIN));
  bits++;
  bits %= 0xFF;
}

void displayBits(){
  digitalWrite(latchPin, LOW);
  shiftOut(serialInputPin, clockPin, MSBFIRST, bits);
  digitalWrite(latchPin, HIGH);
  Serial.println(bits, BIN);
}
