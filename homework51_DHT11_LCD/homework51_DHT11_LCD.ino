/**
 * https://toptechboy.com/arduino-tutorial-51-dht11-temperature-and-humidity-sensor-with-lcd-display/
 * Show temp and humidity on LCD
*/
#include <LiquidCrystal.h>
#include <DHT.h>

#define Type DHT11

const int baud = 9600;
const int delayTime = 1300;

const int sensorPin = 2;

// sensor
DHT HT(sensorPin, Type);

const int rs = 7; // Register select
const int en = 8; // Clock enable
// digital bit pins
const int db4 = 9;
const int db5 = 10;
const int db6 = 11;
const int db7 = 12;

LiquidCrystal lcd(rs, en, db4, db5, db6, db7);

void setup() {
  Serial.begin(baud);
  lcd.begin(16, 2);
  HT.begin();
  delay(delayTime);
}

void loop() {
  float humidity = HT.readHumidity();
  float tempC = HT.readTemperature();
  Serial.println("Humidity: "+String(humidity));
  Serial.println("Temp: "+String(tempC));
  
  displayCount(tempC, humidity);
  delay(delayTime);
}

void displayCount(float temp, float humidity){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: "+String(temp));
  lcd.setCursor(0, 1);
  lcd.print("Humidity: "+String(humidity)+" %");
}
