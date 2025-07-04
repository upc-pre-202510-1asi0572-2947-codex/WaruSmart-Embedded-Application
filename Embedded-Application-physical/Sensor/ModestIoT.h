#ifndef MODEST_IOT_H
#define MODEST_IOT_H

#include "DHTSensor.h"
#include "SoilMoistureSensor.h"
#include "WiFiConnection.h"

// Definiciones globales de pines
#define DHTPIN 4
#define DHTTYPE DHT11
#define SOIL_MOISTURE_PIN 34

// Credenciales WiFi
extern const char* ssid;
extern const char* password;

// Objetos globales
extern DHTSensor dhtSensor;
extern SoilMoistureSensor soilMoistureSensor;
extern WiFiConnection wifiConnection;

#endif
