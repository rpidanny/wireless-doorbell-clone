import pycom
from lib.doorbell import Doorbell

# disable heartbeat led
# pycom.heartbeat(False)

rf_pin = 'G10'

bell = Doorbell(rf_pin)
bell.ring(40)
