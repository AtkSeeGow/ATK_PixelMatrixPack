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
  unsigned long now = millis();
  if (now - this->lastExecutionTime < 500)
    return;
  this->lastExecutionTime = now;

  if (this->step != 1 && this->monsterScreenIndex == 0)
    this->step = 1;
  else if (this->step != 0 && this->attackScreenIndex == 8) {
    this->step = 0;
    this->monsterScreenIndex = 1;
  }

  if (this->step == 0)
    this->drawingMovingScreen();
  else if (this->step == 1)
    this->drawingAttackScreen();
}

void LightsMatrixController::drawingMovingScreen() {
  int maxIndex = sizeof(bindBuffer) - sizeof(monsterBuffer);

  int action = random(0, 2);
  byte* botamon = this->botamons[action];
  memcpy(monsterBuffer, botamon, 8);

  int isFlip = random(0, 2);
  if (isFlip == 0)
    this->flip(monsterBuffer, 8);

  for (int i = 0; i < sizeof(monsterBuffer); i++) {
    int index = this->monsterScreenIndex + i;
    if (index < sizeof(bindBuffer))
      bindBuffer[this->monsterScreenIndex + i] = monsterBuffer[i];
  }

  this->bind();

  int isMoving = random(0, 3);
  if (isMoving == 0)
    this->monsterScreenIndex++;
  else if (isMoving == 1)
    this->monsterScreenIndex--;

  if (this->monsterScreenIndex > maxIndex)
    this->monsterScreenIndex = maxIndex;
  if (this->monsterScreenIndex < 0)
    this->monsterScreenIndex = 0;
}

void LightsMatrixController::drawingAttackScreen() {
  if (this->attackScreenIndex == 8)
    this->monsterTypeIndex = 5;
  else
    this->monsterTypeIndex = 4;

  byte* botamon = this->botamons[this->monsterTypeIndex];
  memcpy(this->monsterBuffer, botamon, 8);
  this->flip(this->monsterBuffer, 8);

  if (this->monsterTypeIndex == 5)
    this->padding(this->monsterBuffer, 8, -2);

  for (int i = 0; i < 8; i++)
    bindBuffer[i] = monsterBuffer[i];

  byte* attack = this->attacks[this->attackTypeIndex];
  for (int i = 0; i < 8; i++) {
    int index = this->attackScreenIndex + i;
    if (index < sizeof(bindBuffer))
      bindBuffer[this->attackScreenIndex + i] = attack[i];
  }

  this->attackScreenIndex++;
  if (this->attackScreenIndex > 16) {
    this->attackScreenIndex = 8;
    this->attackTypeIndex = random(0, 45);
  }

  this->bind();
}

void LightsMatrixController::bind() {
  for (int i = 0; i < 8; i++) {
    this->ledControl.setColumn(1, i, this->bindBuffer[i]);
    this->ledControl.setColumn(0, i, this->bindBuffer[i + 8]);
  }
  memset(this->bindBuffer, 0, sizeof(this->bindBuffer));
}

void LightsMatrixController::flip(byte* data, int size) {
  int index = size - 1;
  for (int i = index; i > -1; i--)
    flipBuffer[index - i] = data[i];
  memcpy(data, flipBuffer, size);
}

void LightsMatrixController::padding(byte* data, int size, int count) {
  for (int i = 0; i < size; i++) {
    int index = 0;
    if (count > 0)
      index = i + count;
    else if (count < 0)
      index = i + abs(count);

    if (index >= size)
      continue;

    if (count > 0)
      paddingBuffer[index] = data[i];
    else if (count < 0)
      paddingBuffer[i] = data[index];
  }

  memcpy(data, paddingBuffer, size);
}
