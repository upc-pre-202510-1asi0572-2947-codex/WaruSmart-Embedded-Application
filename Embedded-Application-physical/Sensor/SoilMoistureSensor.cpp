#include "SoilMoistureSensor.h"

SoilMoistureSensor::SoilMoistureSensor(uint8_t pin) : pin(pin) {}

int SoilMoistureSensor::readMoisture() {
    return analogRead(pin);  // Lectura del sensor de humedad del suelo
}
