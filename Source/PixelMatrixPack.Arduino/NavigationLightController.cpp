//
//
//

#include "NavigationLightController.h"

NavigationLightController::NavigationLightController(int ledPin) {
  this->ledPin = ledPin;
  pinMode(ledPin, OUTPUT);
}

void NavigationLightController::Execution() {
  unsigned long now = millis();
  if (now - this->lastExecutionTime < 10)
    return;
  this->lastExecutionTime = now;

  analogWrite(this->ledPin, brightness);

  if(breathMode)
    brightness++;
  else
    brightness--;

  if(brightness == 200)
    breathMode = false;
  
  if(brightness == 5)
    breathMode = true;
}