void setupMqtt() {
  mqttClient.setServer("test.mosquitto.org", 1883);
  mqttClient.setCallback(receiveCallback);  //function is alled whever we recieve a msg
}

void receiveCallback(char* topic, byte* payload, unsigned int lenght) {
  Serial.println("Message Received");
  Serial.print(topic);
  Serial.println("-----------");

  char payloadCharAr[lenght];

  for (int i = 0; i < lenght; i++) {
    Serial.print((char)payload[i]);
    payloadCharAr[i] = (char)payload[i];
  }
  Serial.println();

  if (strcmp(topic, "USJ-LED") == 0) {
     switchLED(payloadCharAr[0] == '1');
  }
}



void connectToBroker() {
  Serial.println("testing connectedBroker");
  while (!mqttClient.connected()) {
    //Serial.println("testing inside loop");

    Serial.println("Attempting to Connect....");
    if (mqttClient.connect("EPS32-123")) {
      Serial.println("Connected to Broker....");
      mqttClient.subscribe("USJ-LED");
    } else {
      Serial.println("Error!....");
      Serial.println(mqttClient.state());
      delay(5000);
    }
  }
}