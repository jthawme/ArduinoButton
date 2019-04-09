#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button();
    Button(int pin, bool pullupMode);
    bool isDown();
    int getPin();
    void update(void (*)(int, int));

    static const int TAP = 0;
    static const int DOUBLE_TAP = 1;
    static const int LONG_PRESS = 2;
    static const int DOWN = 3;
    static const int RELEASED = 4;
  private:
    void _report(int type, void (*)(int, int));
    int _checker = 0;
    int _pin;
    bool _down = false;
    unsigned long _lastPressed = 0;
    unsigned long _lastReleased = 0;
    int _doubleTapThreshold = 250;
    int _doubleTapResetThreshold = 500;
    int _longPressThreshold = 1000;
    bool _doubleTapped = false;
    bool _longPressed = false;
};

#endif