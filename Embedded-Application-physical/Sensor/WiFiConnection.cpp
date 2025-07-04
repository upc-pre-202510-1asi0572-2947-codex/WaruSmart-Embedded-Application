#include "WiFiConnection.h"
#include <WiFi.h>

/**
 * @brief Constructor for the WiFiConnection class, initializes the SSID and password.
 *
 * @param ssid The SSID of the WiFi network.
 * @param password The password of the WiFi network.
 */
WiFiConnection::WiFiConnection(const char* ssid, const char* password)
    : ssid(ssid), password(password) {}

/**
 * @brief Connects to the WiFi network.
 *
 * This method attempts to connect to the WiFi using the provided SSID and password.
 * It blocks the execution until the connection is established.
 */
void WiFiConnection::connect() {
    WiFi.begin(ssid, password);  // Start WiFi connection using SSID and password
    while (WiFi.status() != WL_CONNECTED) {  // Wait until connected
        delay(1000);  // Delay of 1 second between connection attempts
    }
}
