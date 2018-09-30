import pycom
from machine import Pin
from lib.doorbell import Doorbell

# disable heartbeat led
# pycom.heartbeat(False)

# Pin connected to the RF tx pin
rf_pin = 'G10'

# Pin connected to button
btn_pin = 'G17'

# Init Doorbell
bell = Doorbell(rf_pin)

# Button press handler
def btn_press_handler(arg):
    print('Button pressed, Ringing bell!!')
    bell.ring(40)

# Init button pin
btn = Pin(btn_pin, mode=Pin.IN, pull=Pin.PULL_UP)
# Setup button press callback
btn.callback(Pin.IRQ_FALLING, btn_press_handler)
