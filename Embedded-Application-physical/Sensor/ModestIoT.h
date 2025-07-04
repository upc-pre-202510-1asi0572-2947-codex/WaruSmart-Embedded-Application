#ifndef MODEST_IOT_H
#define MODEST_IOT_H

#include "DHTSensor.h"
#include "SoilMoistureSensor.h"
#include "WiFiConnection.h"

// Pin definitions for the sensors
#define DHTPIN 4                // Pin connected to the DHT sensor
#define DHTTYPE DHT11           // Type of the DHT sensor (DHT11 or DHT22)
#define SOIL_MOISTURE_PIN 34    // Pin connected to the soil moisture sensor

// WiFi credentials
extern const char* ssid;       // WiFi SSID
extern const char* password;   // WiFi password

// Global objects for sensors and WiFi connection
extern DHTSensor dhtSensor;           // DHT sensor object for temperature and humidity
extern SoilMoistureSensor soilMoistureSensor;  // Soil moisture sensor object
extern WiFiConnection wifiConnection;  // WiFi connection object for managing network connectivity

#endif
