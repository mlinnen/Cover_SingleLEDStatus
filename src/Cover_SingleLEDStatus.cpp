#include "Cover_SingleLEDStatus.h"

namespace Cover
{
  SingleLEDStatus::SingleLEDStatus(int ledPin)
  {
    _ledPin = ledPin;
  }

  void SingleLEDStatus::setup()
  {
    // Perform any onetime setup.
    pinMode(_ledPin, OUTPUT);
    _ledFlashTimer.setTimeout(500);
  }

  boolean SingleLEDStatus::loop()
  {
    // This is the service loop that is called from the main program and will update the state of this component.

    // Update the LED state if we are flasing

    // Process any new state changes that came in
    if (_lastState != _currentState)
    {
      switch (_currentState)
      {
      case StateClosed:
        setLED(false);
        break;
      case StateOpen:
        setLED(true);
        break;
      default:
        break;
      }
    }

    LEDFlash();

    _lastState = _currentState;
  }

  void SingleLEDStatus::setState(State state)
  {
    _currentState = state;
  }

  void SingleLEDStatus::setLED(boolean on)
  {
    _ledState = on;
    digitalWrite(_ledPin, _ledState);
  }

  void SingleLEDStatus::toggleLED()
  {
    if (_ledState == LOW)
      _ledState = HIGH;
    else
      _ledState = LOW;
    digitalWrite(_ledPin, _ledState);
  }

  void SingleLEDStatus::LEDFlash()
  {
    if (_currentState == StateOpening || _currentState == StateClosing)
    {
      if (_ledFlashTimer.isExpired())
      {
        toggleLED();
        _ledFlashTimer.restart();
      }
    }
  }
}