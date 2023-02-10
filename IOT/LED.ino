#define LED 2

void switchLED(boolean statusLED) {
  if (statusLED) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}