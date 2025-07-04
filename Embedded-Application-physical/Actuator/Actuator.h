#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <HTTPClient.h>
#include <ArduinoJson.h>

/**
 * @class Actuator
 * @brief Class to control an actuator and send control requests to a server.
 *
 * This class provides methods to control an actuator (e.g., relay, motor)
 * and communicate with a server to receive control instructions.
 */
class Actuator {
private:
    int actuatorPin;  /**< Pin connected to the actuator */

public:
    /**
     * @brief Constructor to initialize the actuator with a specific pin.
     *
     * @param pin Pin connected to the actuator.
     */
    Actuator(int pin);

    /**
     * @brief Controls the actuator based on the provided action.
     *
     * @param action The action that will control the actuator (e.g., "irrigate").
     */
    void controlActuator(String action);

    /**
     * @brief Sends a request to the server to receive control instructions.
     *
     * Sends a JSON payload with device data, receives the server's response,
     * and controls the actuator based on the response.
     */
    void sendRequest();
};

#endif
