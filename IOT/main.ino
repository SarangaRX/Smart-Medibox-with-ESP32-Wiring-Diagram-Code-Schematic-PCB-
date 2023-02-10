
#include <WiFi.h>
//#include <WiFiUdp.h>
#include <PubSubClient.h>

#define LED 2

char tempAr[6];

WiFiClient espClient;
PubSubClient mqttClient(espClient);


void setup() {
  delay(1000);
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  delay(10);

  setupWiFi();
  setupMqtt();
  randomSeed(analogRead(0));
}


void loop() {
  if (!mqttClient.connected()) {
    connectToBroker();
  //  Serial.println("testing connected?=true");
  }
 // Serial.println("testing");
  mqttClient.loop();
  updateTemperature();
  mqttClient.publish("USJ123", tempAr);
  delay(2000);
}
