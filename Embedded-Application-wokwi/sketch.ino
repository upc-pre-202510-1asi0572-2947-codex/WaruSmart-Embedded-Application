#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "red-wifi";
const char* pass = "password";

#define DHTPIN 16
#define DHTTYPE DHT22
#define SOILMOUSTUREPIN 34

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();  

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");
}

void loop() {
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  int16_t soilMoistureValue = analogRead(SOILMOUSTUREPIN);

  // Convertir la lectura a voltaje (3.3V es el rango máximo del ESP32)
  float soilMoistureVoltage = soilMoistureValue * (3.3 / 4095.0);
  
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer el sensor DHT");
  } else {
    // Mostramos los valores en el monitor serial
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" *C");

    Serial.print("Humedad del suelo (Voltaje): ");
    Serial.print(soilMoistureVoltage);
    Serial.print(" V\t");
    Serial.print("Humedad del suelo (%): ");
    int soilMoisturePercentage = (int)((3.3 - soilMoistureVoltage) * 20);
    Serial.println(soilMoisturePercentage);

    HTTPClient http;
    String serverPath = "http://<IP_DE_TU_PC>:<PUERTO>/data";
    http.begin(serverPath);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String httpRequestData = "humedad=" + String(humedad) + "&temperatura=" + String(temperatura) + "&soilMoisture=" + String(soilMoistureVoltage);
    
    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0) {
      Serial.print("Código de respuesta HTTP: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error en la solicitud HTTP: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }

  delay(3000);
}
