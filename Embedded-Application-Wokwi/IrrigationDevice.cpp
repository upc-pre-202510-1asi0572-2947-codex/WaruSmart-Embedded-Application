#include "IrrigationDevice.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino.h>

IrrigationDevice::IrrigationDevice(DhtSensor& dhtSensor, RelayActuator& relay, LedActuator& led)
    : dht(dhtSensor), relay(relay), led(led) {}

void IrrigationDevice::setup() {
    Serial.begin(115200);
    dht.begin();
    relay.begin();
    led.begin();
    connectWiFi();
}

void IrrigationDevice::loop() {
    dht.update();

    if (!dht.valid) {
        Serial.println("Error al leer el sensor");
        delay(2000);
        return;
    }

    Serial.printf("Temperatura: %.1f °C | Humedad: %.1f %%\n", dht.temperature, dht.humidity);

    bool activateIrrigation = (dht.temperature > 30.0 || dht.humidity < 40.0);
    relay.activate(activateIrrigation);
    led.activate(activateIrrigation);

    Serial.println(activateIrrigation ? "Riego ACTIVADO" : "Riego DESACTIVADO");

    String json = "{";
    json += "\"device_id\": \"waru-smart-001\",";
    json += "\"soil_moisture\":" + String(50,1) + ",";
    json += "\"temperature\":" + String(dht.temperature, 1) + ",";
    json += "\"humidity\":" + String(dht.humidity, 1) + ",";
    json += "\"zone\": \"C\"";
    json += "}";


    Serial.println("JSON generate:");
    Serial.println(json);

    sendData(json);

    delay(10000);
}

void IrrigationDevice::connectWiFi() {
    WiFi.begin("Wokwi-GUEST", "");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi conectado.");
}

void IrrigationDevice::sendData(const String& jsonPayload) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;

        // ✅ Apunta al Gateway (IP del simulador)
        http.begin("http://192.168.82.2:9080/api/v1/monitoring/device-metrics"); 

        http.addHeader("Content-Type", "application/json");

        int httpResponseCode = http.POST(jsonPayload);

        if (httpResponseCode > 0) {
            Serial.printf("POST enviado. Código de respuesta: %d\n", httpResponseCode);
            String response = http.getString();
            Serial.println("Respuesta del servidor:");
            Serial.println(response);
        } else {
            Serial.printf("Error en POST: %s\n", http.errorToString(httpResponseCode).c_str());
        }

        http.end();
    } else {
        Serial.println("No hay conexión WiFi para enviar los datos.");
    }
}
