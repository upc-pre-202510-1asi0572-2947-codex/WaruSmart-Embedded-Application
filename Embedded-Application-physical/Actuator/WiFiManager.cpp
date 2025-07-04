#include "WiFiManager.h"
#include <WiFi.h>

/**
 * @brief Connects to the Wi-Fi network using predefined SSID and password.
 *
 * This method attempts to connect to the Wi-Fi network by calling `WiFi.begin()`
 * and repeatedly checks the connection status until the device is connected.
 */
void WiFiManager::connect() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  // Start Wi-Fi connection using SSID and password
    while (WiFi.status() != WL_CONNECTED) {  // Wait until the device is connected
        delay(1000);  // Wait 1 second before checking again
        Serial.println("Connecting to Wi-Fi...");  // Print status to Serial Monitor
    }
    Serial.println("Connected to Wi-Fi");  // Print success message once connected
}

/**
 * @brief Retrieves the IP address assigned to the device after connecting to Wi-Fi.
 *
 * @return The local IP address of the ESP32 as a string.
 */
String WiFiManager::getIP() {
    return WiFi.localIP().toString();  // Return the IP address as a string
}
