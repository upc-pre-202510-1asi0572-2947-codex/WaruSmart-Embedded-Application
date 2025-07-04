#include "DHTSensor.h"

DHTSensor::DHTSensor(uint8_t pin, uint8_t type) : dht(pin, type) {}

void DHTSensor::begin() {
    dht.begin();
}

float DHTSensor::getTemperature() {
    return dht.readTemperature();
}

float DHTSensor::getHumidity() {
    return dht.readHumidity();
}
