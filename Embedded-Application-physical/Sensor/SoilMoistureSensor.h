#ifndef SOIL_MOISTURE_SENSOR_H
#define SOIL_MOISTURE_SENSOR_H

/**
 * @class SoilMoistureSensor
 * @brief Class for interacting with a soil moisture sensor.
 *
 * This class reads the moisture level from a connected soil moisture sensor.
 */
class SoilMoistureSensor {
public:
    /**
     * @brief Constructor to initialize the soil moisture sensor with a specific pin.
     *
     * @param pin Pin connected to the soil moisture sensor.
     */
    SoilMoistureSensor(uint8_t pin);

    /**
     * @brief Reads the moisture level from the soil moisture sensor.
     *
     * @return Moisture level as an integer value.
     */
    int readMoisture();

private:
    uint8_t pin;  /**< Pin connected to the soil moisture sensor */
};

#endif
