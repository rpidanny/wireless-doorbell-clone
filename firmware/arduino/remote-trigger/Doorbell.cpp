#include "Doorbell.h"

Doorbell::Doorbell(uint8_t pin, uint16_t short_pulse, uint16_t long_pulse, uint16_t frame_spacing, bool *frame, uint8_t length) {
  _pin = pin;
  _frame = frame;
  _bit_count = length;
  _long_pulse = long_pulse;
  _short_pulse = short_pulse;
  _frame_spacing = frame_spacing;

  pinMode(_pin, OUTPUT);
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
    digitalWrite(_pin, !digitalRead(_pin));
    delayMicroseconds(_frame[i] ? _long_pulse : _short_pulse);
  }
  digitalWrite(_pin, LOW);
}
