#include <WiFi.h>

const char* ssid = ""; // Change this to your Wi-Fi network name (SSID)
const char* password = ""; //Change this to your Wi-Fi network password
const char* host = ""; //Change this to the IP of the sender device

WiFiClient client;

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println(".");
  }
  Serial.println("Connected to WiFi");

  // Establish a connection to the sender device on port 80
}

void loop() 
{
  if (client.connected()) 
  {
    if (Serial.available()) 
    {
      // Check for data from the Serial Monitor and send it to the sender device
    }
    if (client.available()) 
    {
      // Check for data from the sender device and print it to the Serial Monitor
    }
  }
  else 
  {
    Serial.println("Disconnected from server");
    delay(5000);
    ESP.restart();
  }
}