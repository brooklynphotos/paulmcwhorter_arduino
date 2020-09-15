/*
   https://www.youtube.com/watch?v=rTuKKVcYeMg
   create LEDs that will count from 0 to 15 in binary format
*/

int led_pins[4] = {12, 11, 10, 9};
int led_config[4] = {0, 0, 0, 0};
int current_loop = 0;
void setup()
{
  for(int index=0;index<4; index++){
    pinMode(led_pins[index], OUTPUT);
  }
}

void loop()
{
  blink_leds();
  update_leds();
  current_loop++;
  current_loop %= 16;
}

void update_leds() {
  for (int index = 0; index < 4; index++) {
    if ((current_loop & (1 << index)) == 0) {
      led_config[index] = 0;
    } else {
      led_config[index] = 1;
    }
  }

}

void blink_leds() {
  switch_leds();
  delay(1000);
  turn_off();
  delay(1000);
}

void switch_leds() {
  for (int i = 0; i < 4; i++) {
    if (led_config[i] == 1) {
      digitalWrite(led_pins[i], HIGH);
    }
  }
}
void turn_off() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(led_pins[i], LOW);
  }
}
