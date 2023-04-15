//
//
//

#include "WarningLightController.h"

WarningLightController::WarningLightController() {
}

void WarningLightController::Execution() {
  if (M5.BtnA.wasPressed())
    this->mode++;

  if (this->mode > 2)
    this->mode = 0;

  if (this->mode == 0)
    analogWrite(M5_LED, 255);
  else if (this->mode == 1)
    this->breathingLightMode();
  else if (this->mode == 2)
    this->navigationLightMode();
}

void WarningLightController::breathingLightMode() {
  unsigned long now = millis();
  if (now - this->lastBreathingLightExecutionTime > 10) {
    this->lastBreathingLightExecutionTime = now;

    if (brightnessDirection)
      currentBrightness++;
    else
      currentBrightness--;

    if (currentBrightness == 255)
      brightnessDirection = false;

    if (currentBrightness == 50)
      brightnessDirection = true;
  }

  analogWrite(M5_LED, currentBrightness);
}

void WarningLightController::navigationLightMode() {
  unsigned long now = millis();
  if (now - this->lastNavigationLightExecutionTime > 1000) {
    this->lastNavigationLightExecutionTime = now;
    if (currentBrightness == 255)
      currentBrightness = 50;
    else
      currentBrightness = 255;
  }
  analogWrite(M5_LED, currentBrightness);
}