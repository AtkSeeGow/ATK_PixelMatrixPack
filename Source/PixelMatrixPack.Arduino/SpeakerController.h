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
  
  int sirenFrequencyType = 0;
  int lastSirenFrequencyType = 0;
  int sirenFrequency = 1000;
  unsigned long lastSirenExecutionTime;
  void siren();
};

#endif
