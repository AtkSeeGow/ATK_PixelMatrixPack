//
//
//

#include "LightsMatrixController.h"

LightsMatrixController::LightsMatrixController(int dataPin, int clockPin, int chipSelectPin, int deviceCounnt)
  : ledControl(dataPin, clockPin, chipSelectPin, deviceCounnt) {
  for (byte i = 0; i < this->ledControl.getDeviceCount(); i++) {
    this->ledControl.shutdown(i, false);
    this->ledControl.setIntensity(i, 1);
    this->ledControl.clearDisplay(i);
  }
}

void LightsMatrixController::Execution() {
  this->drawChickAnimation();
}

void LightsMatrixController::drawChickAnimation() {
  unsigned long now = millis();
  if (now - this->lastMovingTime < 500)
    return;
  this->lastMovingTime = now;

  memcpy(convertedIcon, originIcon, sizeof(originIcon));
  if (isMovingRight) {
    int index = sizeof(originIcon) - 1;
    for (int i = index; i > -1; i--)
      convertedIcon[index - i] = originIcon[i];
  }

  memset(image, 0, sizeof(image));
  for (int i = 0; i < sizeof(convertedIcon); i++) {
    int index = this->currentColumnIndex + i;
    if (index < sizeof(image))
      image[this->currentColumnIndex + i] = convertedIcon[i];
  }

  for (int i = 0; i < 8; i++) {
    this->ledControl.setColumn(1, i, image[i]);
    this->ledControl.setColumn(0, i, image[i + 8]);
  }

  if (isMovingRight) {
    this->currentColumnIndex++;
    if (this->currentColumnIndex == sizeof(image))
      isMovingRight = false;
  } else {
    this->currentColumnIndex--;
    if (this->currentColumnIndex == -sizeof(originIcon))
      isMovingRight = true;
  }
}
