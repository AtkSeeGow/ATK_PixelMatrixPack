// LightsMatrixController.h

#ifndef _LIGHTSMATRIXCONTROLLER_h
#define _LIGHTSMATRIXCONTROLLER_h

#include <LedControl.h>

class LightsMatrixController {
public:
  LightsMatrixController(int dataPin, int clockPin, int chipSelectPin, int deviceCounnt);
  void Execution();
private:
  LedControl ledControl;

  void drawChickAnimation();
  bool isMovingRight = true;
  unsigned long lastMovingTime;
  int currentColumnIndex = 5;
  byte convertedIcon[9] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  byte originIcon[9] = { 0x20, 0x5c, 0x82, 0xa1, 0x81, 0x61, 0x21, 0x1a, 0x0c };
  byte image[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
};

#endif
