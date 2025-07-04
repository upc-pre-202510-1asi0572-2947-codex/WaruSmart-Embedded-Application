#ifndef SOIL_MOISTURE_SENSOR_H
#define SOIL_MOISTURE_SENSOR_H

class SoilMoistureSensor {
public:
    SoilMoistureSensor(uint8_t pin);
    int readMoisture();

private:
    uint8_t pin;
};

#endif
