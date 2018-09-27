#ifndef DOORBELL_H
#define DOORBELL_H

class Doorbell {
  public:
    /**
     * @param pin The RF data pin
     * @param bit_length Bit length in microseconds
     * @param frame_spacing Time between two frames in microseconds
     * @param *frame Pointer to array of boolean denoting a frame
     * @param length Number of bits in a frame
     * @return void
     **/
    Doorbell(uint8_t pin, uint16_t bit_length, uint16_t frame_spacing, bool *frame, uint8_t length);
    void ring(uint8_t times = 1);
  private:
    bool *_frame;
    uint9_t _pin; // RF data pin
    uint8_t _bit_count; // number of bits in a frame
    uint16_t _bit_length; // bit length in microseconds
    uint16_t _frame_spacing; // frame spacing in microseconds

    void sendFrame();
};

#endif