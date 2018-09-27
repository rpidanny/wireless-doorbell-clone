#include <Arduino.h>
#include "Doorbell.h"

#define short_pulse 475
#define long_pulse 1435

// 0: short, 1: long
bool frame[35] = {
  0, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 0,
  1, 0, 1, 1, 0, 1, 0,
  1, 0, 0, 1, 1, 0, 0,
  1, 0, 1, 0, 1, 0, 1
};

Doorbell d1(13, short_pulse, long_pulse, 8667, frame, 35);

void setup() {
  // put your setup code here, to run once:
  d1.ring(40);
}

void loop() {
  // put your main code here, to run repeatedly:
}
