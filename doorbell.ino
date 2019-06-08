//esp8266 doorbell
//getting notified by a push notification on your phone!
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "*******";
const char* password = "******";

const int buttonPin = 2;
int buttonState = 0;
  
void setup() {
  Serial.begin(74880);
  connectToWifi();
}

void connectToWifi(){
  
  Serial.println("- Connecting to the router SSID: " + String(ssid));
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("- succesfully connected");
  Serial.println("- starting client");
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    WiFiClient client;
    
    Serial.println("- sending api calll...");
    
    HTTPClient hclient;
    
    hclient.begin("******");
    int httpCode = hclient.GET();
    
    if(httpCode > 0) {
      String payload  = hclient.getString();
      Serial.println(payload);
    }
    hclient.end();
  }
}
