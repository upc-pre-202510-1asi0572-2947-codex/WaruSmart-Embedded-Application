#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Galaxy A12 313E";
const char* password = "jpvm6020";

const char* serverURL = "http://192.168.244.109:5000/api/v1/actuators/status";  // URL del servidor Flask
int actuatorPin = 23;  // Configura el pin del actuador (ejemplo, GPIO13)

void setup() {
  Serial.begin(115200);
  pinMode(actuatorPin, OUTPUT);  // Configura el pin como salida

  // Conexión Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a Wi-Fi...");
  }

  Serial.println("Conectado al Wi-Fi");
  Serial.print("IP del ESP32: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Esperar 5 segundos antes de hacer la siguiente consulta
  delay(5000);

  // Hacer una solicitud GET al servidor Edge para obtener el estado del actuador
  HTTPClient http;
  http.begin(serverURL);

  int httpResponseCode = http.GET();
  
  if (httpResponseCode > 0) {
    // Leer la respuesta JSON
    String payload = http.getString();
    Serial.println(payload);

    // Parsear el JSON para obtener el valor de la acción
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, payload);
    String action = doc["action"];
    float soil_moisture = doc["soil_moisture"];

    // Según la acción recibida, activar o desactivar el actuador
    if (action == "irrigate") {
      digitalWrite(actuatorPin, HIGH);  // Activar el actuador (encender la bomba)
      Serial.println("Actuador activado (Riego)");
    } else if (action == "deactivate") {
      digitalWrite(actuatorPin, LOW);  // Desactivar el actuador (apagar la bomba)
      Serial.println("Actuador desactivado");
    }
  } else {
    Serial.println("Error al hacer la solicitud HTTP");
  }

  http.end();  // Finalizar la solicitud HTTP
}
