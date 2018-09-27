#include <Arduino.h>
#include "Doorbell.h"

#define pin 13
#define short_pulse 475
#define long_pulse 1435
#define frame_interval 8667
// 0: short, 1: long
bool frame[35] = {
  0, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 0,
  1, 0, 1, 1, 0, 1, 0,
  1, 0, 0, 1, 1, 0, 0,
  1, 0, 1, 0, 1, 0, 1
};

Doorbell d1(pin, short_pulse, long_pulse, frame_interval, frame, 35);

void setup() {
  // put your setup code here, to run once:
  d1.ring(40);
}

void loop() {
  // put your main code here, to run repeatedly:
}
