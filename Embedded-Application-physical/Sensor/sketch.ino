#include "ModestIoT.h"

// Initialize sensor and WiFi objects with the specified pins and credentials
DHTSensor dhtSensor(DHTPIN, DHTTYPE);                  // DHT sensor for temperature and humidity
SoilMoistureSensor soilMoistureSensor(SOIL_MOISTURE_PIN);  // Soil moisture sensor
WiFiConnection wifiConnection(ssid, password);        // WiFi connection object

void setup() {
    Serial.begin(115200);  // Initialize serial communication at 115200 baud rate

    // Connect to WiFi
    wifiConnection.connect();

    // Initialize sensors
    dhtSensor.begin();  // Start the DHT sensor
}

void loop() {
    // Read temperature and humidity from the DHT sensor
    float temperature = dhtSensor.getTemperature();
    float humidity = dhtSensor.getHumidity();

    // Read soil moisture from the soil moisture sensor
    int moisture = soilMoistureSensor.readMoisture();

    // Print the sensor readings to the serial monitor
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.print("Soil Moisture: ");
    Serial.println(moisture);

    delay(2000);  // Wait for 2 seconds before the next loop
}
