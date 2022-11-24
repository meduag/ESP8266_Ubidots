#include <Ubidots.h>

#define UBIDOTS_TOKEN "BBFF-THEyBBLGfTxR4xaGrar3EraxqDNO6A"  // Put here your Ubidots TOKEN
#define DEVICE_LABEL "ControleLed"  // Put here your Ubidots device label

#define LED  "blink"

char const * WIFI_SSID = "CLARO_2GC4D901"; // Put here your Wi-Fi SSID
char const * WIFI_PASS = "vaitomarnocu123"; // Put here your Wi-Fi password

Ubidots controle(UBIDOTS_TOKEN, UBI_HTTP);

bool led = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Teste Ubidots - Blink");

  controle.wifiConnect(WIFI_SSID, WIFI_PASS);
}

void loop() {
  controle.add(LED, led);

  controle.send(DEVICE_LABEL);

  delay(2000);
  led = !led;
}
