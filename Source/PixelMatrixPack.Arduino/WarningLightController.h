// WarningLightController.h

#ifndef _WARNINGLIGHTCONTROLLER_h
#define _WARNINGLIGHTCONTROLLER_h

#include <Arduino.h>
#include <M5StickCPlus.h>
#include "utility/Config.h"

class WarningLightController {
public:
  WarningLightController();
  void Execution();
private:
  int mode = 0;

  unsigned long lastExecutionTime;
  int currentBrightness = 100;

  bool brightnessDirection = true;
  int breathFrequency = 10;
  void breathingLightMode();

  int navigationFrequency = 1000;
  void navigationLightMode();
};

#endif
