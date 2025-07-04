#include <Arduino.h>
#include "ModestIoT.h"
#include "WiFiManager.h"
#include "Actuator.h"

WiFiManager wifiManager;
Actuator actuator(23);  // GPIO23 para el actuador

void setup() {
    Serial.begin(115200);
    wifiManager.connect();
    Serial.print("IP del ESP32: ");
    Serial.println(wifiManager.getIP());
}

void loop() {
    delay(5000);
    actuator.sendRequest();
}
