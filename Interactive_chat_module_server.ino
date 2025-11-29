#include <WiFi.h>

const char* ssid = "Santhosh";
const char* password = "87654321";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("Client connected");

    while (client.connected()) {
      if (Serial.available()) {
        client.write(Serial.read());
      }
      if (client.available()) {
        Serial.write(client.read());
      }
    }

    client.stop();
    Serial.println("Client disconnected");
  }
}
