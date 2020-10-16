/**
 * https://toptechboy.com/arduino-tutorial-49-how-to-build-a-simple-calculator-with-lcd-display/
 * Show a calculator on the LCD
*/
#include <LiquidCrystal.h>

const int baud = 9600;
const int delayTime = 1000;

const int rs = 7; // Register select
const int en = 8; // Clock enable
// digital bit pins
const int db4 = 9;
const int db5 = 10;
const int db6 = 11;
const int db7 = 12;

int currentCount = 1;

LiquidCrystal lcd(rs, en, db4, db5, db6, db7);

void setup() {
  Serial.begin(baud);
  lcd.begin(16, 2);
}

void loop() {
  displayCount(currentCount++);
  delay(delayTime);
}

void displayCount(int number){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello World");
  lcd.setCursor(0, 1);
  lcd.print(number);
}
