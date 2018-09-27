#include "Doorbell.h"

Doorbell::Doorbell(uint8_t pin) {
  PinMode(pin, OUTPUT);
}

void Doorbell::ring(uint8_t times) {
  for (uint8_t i = 0; i < times; i++) {
    // Ring button
  }
}