#include "WIFI.h"
const * char ssid ="Family EP";
const* char password ="";
void setup() {
 Serial.begin(152000);
 WiFi.begin (ssid, password);
 while (WiFi.status() =! WL_CONNECTED){
    delay(500);
    Serial.println("Connecting to WIFI...");
  }
  Serial.println("connected to the wifi network");

}

void loop() {
  // put your main code here, to run repeatedly:

}
