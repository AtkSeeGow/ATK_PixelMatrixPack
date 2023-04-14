#include <M5StickCPlus.h>
#include <WiFi.h>
#include "LightsMatrixController.h"
#include "WarningLightController.h"
#include "SpeakerController.h"

LightsMatrixController lightsMatrixController = LightsMatrixController(25, 0, 26, 2);
WarningLightController warningLightController = WarningLightController();
SpeakerController speakerController = SpeakerController();

void setup() {
  M5.begin();
  M5.Axp.ScreenBreath(0);
  M5.Axp.ScreenSwitch(false);
  WiFi.disconnect(true);
  setCpuFrequencyMhz(10);
}

void loop() {
  M5.update();
  lightsMatrixController.Execution();
  warningLightController.Execution();
  speakerController.Execution();
}
