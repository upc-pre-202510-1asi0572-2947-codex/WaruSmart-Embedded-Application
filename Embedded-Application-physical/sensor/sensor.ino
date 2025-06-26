{\rtf1\ansi\ansicpg1252\cocoartf2821
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include "DHT.h"\
#include <WiFi.h>\
#include <HTTPClient.h>\
\
// Configura el pin donde conectaste el DHT11\
#define DHTPIN 4  // Por ejemplo GPIO4, cambia seg\'fan tu conexi\'f3n\
#define DHTTYPE DHT11\
\
const char* ssid = "Galaxy A12 313E";\
const char* password = "jpvm6020";\
\
DHT dht(DHTPIN, DHTTYPE);\
\
const char* serverUrl = "http://192.168.244.184:5000/api/v1/monitoring/device-metrics";\
const char* api_key = "test-api-key-123";\
\
const char* device_id = "waru-smart-001";\
const char* zone = "A"; \
\
void setup() \{\
  Serial.begin(115200);\
  dht.begin();\
\
  WiFi.begin(ssid, password);\
  while (WiFi.status() != WL_CONNECTED) \{\
    delay(1000);\
    Serial.println("Esperando conexi\'f3n...");\
  \}\
\
  Serial.println("Conectado a Wi-Fi");\
  Serial.print("IP del ESP32: ");\
  Serial.println(WiFi.localIP());\
\}\
\
void loop() \{\
  // Espera para lectura estable\
  delay(2000);\
\
  // Lee humedad\
  float humedad = dht.readHumidity();\
  // Lee temperatura en Celsius\
\
  float temperatura = dht.readTemperature();\
\
  // Verifica si falla la lectura\
  if (isnan(humedad) || isnan(temperatura)) \{\
    Serial.println("\'a1Fallo al leer el sensor DHT11!");\
    return;\
  \}\
\
  // Crear el JSON para la temperatura\
  String temperatureJson = "\{\\"device_id\\": \\"" + String(device_id) + "\\", \\"metric_type\\": \\"temperature\\", \\"value\\": " + temperatura + ", \\"zone\\": \\"" + String(zone) + "\\", \\"unit\\": \\"C\\"\}";\
\
  // Crear el JSON para la humedad\
  String humidityJson = "\{\\"device_id\\": \\"" + String(device_id) + "\\", \\"metric_type\\": \\"humidity\\", \\"value\\": " + humedad + ", \\"zone\\": \\"" + String(zone) + "\\", \\"unit\\": \\"%\\"\}";\
\
  // Enviar los datos al servidor\
  if (WiFi.status() == WL_CONNECTED) \{\
    HTTPClient http;\
    http.begin(serverUrl);\
    http.addHeader("Content-Type", "application/json");\
    http.addHeader("x-api-key", api_key);\
\
    // Enviar la temperatura\
    int httpResponseCode = http.POST(temperatureJson);\
    if (httpResponseCode > 0) \{\
      Serial.print("C\'f3digo de respuesta HTTP (Temperatura): ");\
      Serial.println(httpResponseCode);\
    \} else \{\
      Serial.print("Error en la solicitud HTTP (Temperatura): ");\
      Serial.println(httpResponseCode);\
    \}\
\
    // Enviar la humedad\
    httpResponseCode = http.POST(humidityJson);\
    if (httpResponseCode > 0) \{\
      Serial.print("C\'f3digo de respuesta HTTP (Humedad): ");\
      Serial.println(httpResponseCode);\
    \} else \{\
      Serial.print("Error en la solicitud HTTP (Humedad): ");\
      Serial.println(httpResponseCode);\
    \}\
\
    // Finalizar la solicitud HTTP\
    http.end();\
  \}\
\
  // Imprime en consola\
  Serial.print("Humedad: ");\
  Serial.print(humedad);\
  Serial.print(" %\\t");\
  Serial.print("Temperatura: ");\
  Serial.print(temperatura);\
  Serial.println("\'a0\'b0C");\
\}}