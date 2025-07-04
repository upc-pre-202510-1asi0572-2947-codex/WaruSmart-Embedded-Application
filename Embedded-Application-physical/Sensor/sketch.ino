#include "ModestIoT.h"

// Inicialización de objetos
DHTSensor dhtSensor(DHTPIN, DHTTYPE);
SoilMoistureSensor soilMoistureSensor(SOIL_MOISTURE_PIN);
WiFiConnection wifiConnection(ssid, password);

void setup() {
    Serial.begin(115200);

    // Conectar al WiFi
    wifiConnection.connect();

    // Iniciar sensores
    dhtSensor.begin();
}

void loop() {
    // Leer temperatura y humedad
    float temperature = dhtSensor.getTemperature();
    float humidity = dhtSensor.getHumidity();

    // Leer humedad del suelo
    int moisture = soilMoistureSensor.readMoisture();

    // Mostrar los datos
    Serial.print("Temperatura: ");
    Serial.println(temperature);
    Serial.print("Humedad: ");
    Serial.println(humidity);
    Serial.print("Humedad del suelo: ");
    Serial.println(moisture);

    delay(2000);
}
