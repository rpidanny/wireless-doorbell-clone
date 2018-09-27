#include "Doorbell.h"

Doorbell::Doorbell(uint8_t pin, uint16_t bit_length, uint16_t frame_spacing, bool *frame, uint8_t length) {
  _pin = pin;
  _frame = frame;
  _bit_count = length;
  _bit_length = bit_length;
  _frame_spacing = frame_spacing;

  PinMode(_pin, OUTPUT);
}

void Doorbell::ring(uint8_t times) {
  for (uint8_t i = 0; i < times; i++) {
    // Ring button
    sendFrame();
    delayMicroseconds(_frame_spacing);
  }
}

void Doorbell::sendFrame() {
  for (uint8_t i = 0; i < _bit_count; i++) {
    digitalWrite(_pin, _frame[i]);
    delayMicroseconds(_bit_length);
  }
}