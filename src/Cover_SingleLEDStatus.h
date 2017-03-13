#ifndef SingleLEDStatus_h
#define SingleLEDStatus_h

#include "Arduino.h"
#include <RBD_Timer.h>
#include "Cover_Core.h"


namespace Cover
{
  class SingleLEDStatus
  {
    public:
      SingleLEDStatus(int ledPin);
      void setup();
      void subscribe();
      boolean loop();
      void setState(State state);
    private:
      int _ledPin;
      int _ledState = LOW;
      State _currentState;
      State _lastState;
      RBD::Timer _ledFlashTimer;
      void LEDFlash();
      void setLED(boolean on);
      void toggleLED();
  };
}

#endif