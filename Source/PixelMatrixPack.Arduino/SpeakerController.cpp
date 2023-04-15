//
//
//

#include "SpeakerController.h"

SpeakerController::SpeakerController() {
}

void SpeakerController::Execution() {
  if (M5.BtnB.wasPressed())
    this->mode++;

  if (this->mode > 1)
    this->mode = 0;

  if (this->mode == 0)
    M5.Beep.mute();
  else if (this->mode == 1)
    siren();
}

void SpeakerController::siren() {
  unsigned long now = millis();
  if (now - this->lastSirenExecutionTime > 500) {
    this->sirenFrequencyType++;
    this->lastSirenExecutionTime = now;
  }

  if (this->sirenFrequencyType > 1)
    this->sirenFrequencyType = 0;

  if (this->sirenFrequencyType != this->lastSirenFrequencyType) {
    if (this->sirenFrequencyType == 0)
      M5.Beep.tone(20000);
    else
      M5.Beep.tone(30000);
    this->lastSirenFrequencyType = this->sirenFrequencyType;
  }
}
