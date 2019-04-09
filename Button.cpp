#include "Arduino.h"
#include "Button.h"

Button::Button() {}

Button::Button(int pin, bool pullupMode)
{
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _checker = pullupMode ? LOW : HIGH;
}

bool Button::isDown()
{
    return _down;
}

void Button::update(void (*onEvent)(int, int))
{
    int buttonState = digitalRead(_pin);
    bool downCheck = (buttonState == _checker);

    unsigned long now = millis();

    if (downCheck != _down) {

        if (downCheck) {
            _report(Button::DOWN, onEvent);
            _lastPressed = millis();
        } else {
            if (!_longPressed) {
                if (now - _lastReleased < _doubleTapThreshold && !_doubleTapped) {
                    _report(Button::DOUBLE_TAP, onEvent);
                    _doubleTapped = true;
                } else {
                    _report(Button::TAP, onEvent);
                }
            }

            _report(Button::RELEASED, onEvent);

            _lastReleased = now;
            _longPressed = false;
        }
    } else {
        if (downCheck) {
            if (now - _lastPressed > _longPressThreshold && !_longPressed) {
                _report(Button::LONG_PRESS, onEvent);
                _longPressed = true;
            }
        } else {
            if (now - _lastReleased > _doubleTapResetThreshold && _doubleTapped) {
                _doubleTapped = false;
            }
        }
    }

    _down = downCheck;
}

int Button::getPin() {
    return _pin;
}

void Button::_report(int type, void (*onEvent)(int, int)) {
    onEvent(_pin, type);
}