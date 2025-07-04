#include "DHTSensor.h"

// Constructor initializes the DHT sensor with the given pin and type
DHTSensor::DHTSensor(uint8_t pin, uint8_t type) : dht(pin, type) {}

// Initializes the DHT sensor
void DHTSensor::begin() {
    dht.begin();  // Begin DHT sensor communication
}

// Returns the temperature read from the DHT sensor
float DHTSensor::getTemperature() {
    return dht.readTemperature();  // Get the temperature value from the sensor
}

// Returns the humidity read from the DHT sensor
float DHTSensor::getHumidity() {
    return dht.readHumidity();  // Get the humidity value from the sensor
}
