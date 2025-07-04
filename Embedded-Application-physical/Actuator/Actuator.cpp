#include "Actuator.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "ModestIoT.h"

/**
 * @brief Constructor for Actuator class, initializes the pin and sets it as OUTPUT.
 *
 * @param pin The pin connected to the actuator.
 */
Actuator::Actuator(int pin) {
    actuatorPin = pin;  // Store the pin number
    pinMode(actuatorPin, OUTPUT);  // Set the pin mode to OUTPUT
}

/**
 * @brief Sends a request to the server to control the actuator.
 *
 * This method sends a JSON payload with device information to the server,
 * receives a response, and controls the actuator based on the server's response.
 */
void Actuator::sendRequest() {
    DynamicJsonDocument doc(1024);
    doc["device_id"] = "waru-smart-001";  // Set device ID

    String jsonPayload;
    serializeJson(doc, jsonPayload);  // Convert JSON document to string

    HTTPClient http;
    http.begin(SERVER_URL);  // Start HTTP connection to the server
    http.addHeader("Content-Type", "application/json");  // Set content type for POST request

    int httpResponseCode = http.POST(jsonPayload);  // Send POST request with JSON payload
    if (httpResponseCode > 0) {
        String payload = http.getString();  // Get response from server
        Serial.println("Server response: ");
        Serial.println(payload);

        // Parse the JSON response from the server
        DynamicJsonDocument responseDoc(1024);
        deserializeJson(responseDoc, payload);

        String action = responseDoc["action"];  // Extract action from the server response
        float soil_moisture = responseDoc["soil_moisture"];  // Extract soil moisture (if needed)

        controlActuator(action);  // Control the actuator based on the action from the server
    }
}

/**
 * @brief Controls the actuator based on the given action.
 *
 * If the action is "irrigate", it activates the actuator; otherwise, it deactivates it.
 *
 * @param action The action that determines if the actuator should be turned on or off.
 */
void Actuator::controlActuator(String action) {
    if (action == "irrigate") {
        digitalWrite(actuatorPin, HIGH);  // Activate the actuator (turn on)
        Serial.println("Actuator activated (Irrigation)");
    } else {
        digitalWrite(actuatorPin, LOW);   // Deactivate the actuator (turn off)
        Serial.println("Actuator deactivated");
    }
}
