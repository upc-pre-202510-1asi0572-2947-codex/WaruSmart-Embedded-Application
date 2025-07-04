#include "WiFiManager.h"
#include <WiFi.h>

void WiFiManager::connect() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando a Wi-Fi...");
    }
    Serial.println("Conectado al Wi-Fi");
}

String WiFiManager::getIP() {
    return WiFi.localIP().toString();
}
