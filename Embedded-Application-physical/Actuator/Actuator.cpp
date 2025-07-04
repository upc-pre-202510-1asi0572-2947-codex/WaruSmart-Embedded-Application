#include "Actuator.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "ModestIoT.h"

Actuator::Actuator(int pin) {
    actuatorPin = pin;
    pinMode(actuatorPin, OUTPUT);
}

void Actuator::sendRequest() {
    DynamicJsonDocument doc(1024);
    doc["device_id"] = "waru-smart-001";

    String jsonPayload;
    serializeJson(doc, jsonPayload);

    HTTPClient http;
    http.begin(SERVER_URL);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(jsonPayload);
    if (httpResponseCode > 0) {
        String payload = http.getString();
        Serial.println("Respuesta del servidor: ");
        Serial.println(payload);

        DynamicJsonDocument responseDoc(1024);
        deserializeJson(responseDoc, payload);

        String action = responseDoc["action"];
        float soil_moisture = responseDoc["soil_moisture"];

        controlActuator(action);
    }
}

void Actuator::controlActuator(String action) {
    if (action == "irrigate") {
        digitalWrite(actuatorPin, HIGH);  // Activar el actuador
        Serial.println("Actuador activado (Riego)");
    } else {
        digitalWrite(actuatorPin, LOW);   // Desactivar el actuador
        Serial.println("Actuador desactivado");
    }
}
