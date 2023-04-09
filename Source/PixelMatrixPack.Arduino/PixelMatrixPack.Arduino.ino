#include <M5StickCPlus.h>
#include "LightsMatrixController.h"
#include "NavigationLightController.h"

LightsMatrixController lightsMatrixController(25, 0, 26, 2);
NavigationLightController navigationLightController(10);

void setup() {
  M5.begin();
}

void loop() {
  lightsMatrixController.Execution();
  navigationLightController.Execution();
}
