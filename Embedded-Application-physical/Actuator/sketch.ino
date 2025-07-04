#include <Arduino.h>
#include "ModestIoT.h"
#include "WiFiManager.h"
#include "Actuator.h"

// Create WiFiManager object to manage WiFi connection
WiFiManager wifiManager;

// Create Actuator object connected to GPIO23
Actuator actuator(23);  // GPIO23 for the actuator

void setup() {
    Serial.begin(115200);  // Initialize serial communication at 115200 baud rate

    // Connect to WiFi using the WiFiManager
    wifiManager.connect();

    // Print the IP address assigned to the ESP32
    Serial.print("ESP32 IP Address: ");
    Serial.println(wifiManager.getIP());
}

void loop() {
    delay(5000);  // Wait for 5 seconds before sending the next request

    // Send a request to the server to control the actuator
    actuator.sendRequest();
}
