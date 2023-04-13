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
  if (now - this->lastExecutionTime > this->breathFrequency) {
    this->lastExecutionTime = now;

    analogWrite(M5_LED, currentBrightness);

    if (brightnessDirection)
      currentBrightness++;
    else
      currentBrightness--;

    if (currentBrightness == 255)
      brightnessDirection = false;

    if (currentBrightness == 50)
      brightnessDirection = true;
  }
}

void WarningLightController::navigationLightMode() {
  unsigned long now = millis();
  if (now - this->lastExecutionTime > this->navigationFrequency) {
    this->lastExecutionTime = now;
    analogWrite(M5_LED, currentBrightness);
    if (currentBrightness == 255)
      currentBrightness = 50;
    else
      currentBrightness = 255;
  }
}