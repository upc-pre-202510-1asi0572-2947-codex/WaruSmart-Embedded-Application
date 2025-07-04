#include "SoilMoistureSensor.h"

// Constructor to initialize the pin connected to the soil moisture sensor
SoilMoistureSensor::SoilMoistureSensor(uint8_t pin) : pin(pin) {}

// Reads the moisture level from the soil moisture sensor
int SoilMoistureSensor::readMoisture() {
    return analogRead(pin);  // Read the analog value from the soil moisture sensor pin
}
