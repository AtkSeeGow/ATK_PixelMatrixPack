// NavigationLightController.h

#ifndef _NAVIGATIONLIGHTCONTROLLER_h
#define _NAVIGATIONLIGHTCONTROLLER_h

#include <Arduino.h>

class NavigationLightController {
public:
  NavigationLightController(int ledPin);
  void Execution();
private:
  int ledPin;
  int brightness = 100;
  bool breathMode = true;
  unsigned long lastExecutionTime;
};

#endif
