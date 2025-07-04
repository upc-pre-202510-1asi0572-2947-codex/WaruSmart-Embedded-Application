                                                  #include "ModestIoT.h"
#include "DhtSensor.h"
#include "RelayActuator.h"
#include "LedActuator.h"
#include "IrrigationDevice.h"


DhtSensor dht(15);
RelayActuator relay(14);
LedActuator led(12);
IrrigationDevice device(dht, relay, led);

void setup() {
  device.setup();
}

void loop() {
  device.loop();
}
