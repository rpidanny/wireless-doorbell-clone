from time import sleep_us
from machine import Pin

class Doorbell:
    _frame = [
      0, 1, 0, 1, 0, 0, 1,
      1, 0, 0, 1, 0, 1, 0,
      1, 0, 1, 1, 0, 1, 0,
      1, 0, 0, 1, 1, 0, 0,
      1, 0, 1, 0, 1, 0, 1
    ]
    # (short_pulse_duration, long_pulse_duration)
    _pulse_timings = (475, 1435)
    _frame_spacing = 8667

    def __init__(self, pin):
        self.pin = Pin(pin, Pin.OUT)


    def send_frame(self):
        for f in self._frame:
            self.pin.toggle()
            sleep_us(self._pulse_timings[f])
        self.pin.value(0)


    def ring(self, times):
        for i in range(times):
            self.send_frame()
            sleep_us(self._frame_spacing)
