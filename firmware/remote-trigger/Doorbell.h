#ifndef DOORBELL_H
#define DOORBELL_H

class Doorbell {
  public:
    Doorbell(uint8_t pin);
    void ring(uint8_t times = 1);
};

#endif