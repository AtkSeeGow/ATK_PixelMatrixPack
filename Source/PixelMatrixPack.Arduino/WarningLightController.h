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

  int currentBrightness = 100;

  bool brightnessDirection = true;
  unsigned long lastBreathingLightExecutionTime;
  void breathingLightMode();

  unsigned long lastNavigationLightExecutionTime;
  void navigationLightMode();
};

#endif
