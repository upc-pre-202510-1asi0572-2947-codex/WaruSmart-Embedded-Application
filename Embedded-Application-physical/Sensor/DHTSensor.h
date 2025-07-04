#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <DHT.h>

/**
 * @class DHTSensor
 * @brief Class for reading temperature and humidity from a DHT sensor.
 *
 * This class abstracts the interaction with a DHT sensor, providing methods
 * to initialize the sensor and read temperature and humidity values.
 */
class DHTSensor {
public:
    /**
     * @brief Constructor for the DHTSensor class.
     *
     * @param pin Pin connected to the DHT sensor.
     * @param type Type of the DHT sensor (e.g., DHT11 or DHT22).
     */
    DHTSensor(uint8_t pin, uint8_t type);

    /**
     * @brief Initializes the DHT sensor.
     */
    void begin();

    /**
     * @brief Retrieves the current temperature from the DHT sensor.
     *
     * @return Temperature in Celsius.
     */
    float getTemperature();

    /**
     * @brief Retrieves the current humidity from the DHT sensor.
     *
     * @return Humidity in percentage.
     */
    float getHumidity();

private:
    DHT dht;  /**< DHT sensor object */
};

#endif
