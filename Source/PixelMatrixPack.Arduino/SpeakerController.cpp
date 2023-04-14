//
//
//

#include "SpeakerController.h"

SpeakerController::SpeakerController() {
}

void SpeakerController::Execution() {
  if (M5.BtnB.wasPressed())
    this->mode++;

  if (this->mode > 2)
    this->mode = 0;

  // M5.Beep.tone(4000);
}
