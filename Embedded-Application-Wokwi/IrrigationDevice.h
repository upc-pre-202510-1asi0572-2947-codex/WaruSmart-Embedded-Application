#ifndef IRRIGATION_DEVICE_H
#define IRRIGATION_DEVICE_H

#include "ModestIoT.h"
#include "DhtSensor.h"
#include "RelayActuator.h"
#include "LedActuator.h"

class IrrigationDevice : public Device {
public:
    IrrigationDevice(DhtSensor& dhtSensor, RelayActuator& relay, LedActuator& led);

    void setup() override;
    void loop() override;

private:
    DhtSensor& dht;
    RelayActuator& relay;
    LedActuator& led;

    void connectWiFi();
    void sendData(const String& jsonPayload);
};

#endif
