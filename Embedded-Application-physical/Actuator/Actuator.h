#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <HTTPClient.h>
#include <ArduinoJson.h>

class Actuator {
private:
    int actuatorPin;
public:
    Actuator(int pin);
    void controlActuator(String action);
    void sendRequest();
};

#endif
