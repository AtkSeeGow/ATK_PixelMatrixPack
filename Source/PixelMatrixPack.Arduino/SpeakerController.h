// SpeakerController.h

#ifndef _SPEAKERCONTROLLER_h
#define _SPEAKERCONTROLLER_h

#include <Arduino.h>
#include <M5StickCPlus.h>

class SpeakerController {
public:
  SpeakerController();
  void Execution();
private:
  int mode = 0;
};

#endif
