//
//
//

#include "LightsMatrixController.h"

LightsMatrixController::LightsMatrixController(int dataPin, int clockPin, int chipSelectPin, int deviceCount)
  : ledControl(dataPin, clockPin, chipSelectPin, deviceCount) {
  for (byte i = 0; i < this->ledControl.getDeviceCount(); i++) {
    this->ledControl.shutdown(i, false);
    this->ledControl.setIntensity(i, 0);
    this->ledControl.clearDisplay(i);
  }
}

void LightsMatrixController::Execution() {
  this->drawMoving();
}

void LightsMatrixController::drawMoving() {
  unsigned long now = millis();
  if (now - this->lastExecutionTime < 500)
    return;
  this->lastExecutionTime = now;

  int action = random(0, 2);
  for(int i = 0; i < sizeof(this->botamon[action]); i++)
    this->converted[i] = this->botamon[action][i];

  memset(image, 0, sizeof(image));
  for (int i = 0; i < sizeof(converted); i++) {
    int index = this->imageIndex + i;
    if (index < sizeof(image))
      image[this->imageIndex + i] = converted[i];
  }

  for (int i = 0; i < 8; i++) {
    this->ledControl.setColumn(1, i, image[i]);
    this->ledControl.setColumn(0, i, image[i + 8]);
  }

  int vector = random(0, 2);
  if (vector == 0)
    this->imageIndex++;
  else
    this->imageIndex--;

  int maxIndex = sizeof(image) - sizeof(converted);
  if (this->imageIndex > maxIndex)
    this->imageIndex = maxIndex;
  if (this->imageIndex < 0)
    this->imageIndex = 0;
}
