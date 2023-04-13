#include <M5StickCPlus.h>
#include "WiFi.h"
#include "LightsMatrixController.h"
#include "NavigationLightController.h"

LightsMatrixController lightsMatrixController(25, 0, 26, 2);
NavigationLightController navigationLightController(10);

void setup() {
  M5.begin();
  M5.Axp.ScreenBreath(0);
  M5.Axp.ScreenSwitch(false);
  WiFi.mode(WIFI_OFF);
  setCpuFrequencyMhz(60);
  Serial.begin(9600);
}

void loop() {
  lightsMatrixController.Execution();
  navigationLightController.Execution();
}
