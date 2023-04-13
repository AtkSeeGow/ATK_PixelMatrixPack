#include <M5StickCPlus.h>
#include "LightsMatrixController.h"
#include "WarningLightController.h"

LightsMatrixController lightsMatrixController(25, 0, 26, 2);
WarningLightController warningLightController;

void setup() {
  M5.begin(false, false , false);
  Serial.begin(9600);
}

unsigned long lastLoopTime;
void loop() {
  M5.update();
  lightsMatrixController.Execution();
  warningLightController.Execution();

  unsigned long now = millis();
  if (now - lastLoopTime > 250) {
    lastLoopTime = now;
    Serial.printf("%.3fma\r\n", M5.Axp.GetVBusCurrent());
  }
}
