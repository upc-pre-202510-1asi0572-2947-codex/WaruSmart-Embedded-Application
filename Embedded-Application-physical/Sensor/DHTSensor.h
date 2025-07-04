#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <DHT.h>

class DHTSensor {
public:
    DHTSensor(uint8_t pin, uint8_t type);
    void begin();
    float getTemperature();
    float getHumidity();

private:
    DHT dht;
};

#endif
