# Arduino Button

A simple button wrapper that allows you to add some logic to buttons with Arduino.


## Example
```
Button btn = Button(7, false);

void setup() {

}

void loop() {
    btn.update(onStateChange);
}

void onStateChange(int pin, int eventType) {
    switch (eventType) {
        case Button::TAP:
            break;
        case Button::DOUBLE_TAP:
            break;
        case Button::LONG_PRESS:
            break;
        case Button::DOWN:
            break;
        case Button::RELEASED:
            break;
    }
}
```

## Documentation
**Button(int pin, bool pullupMode)**
- *pin* - The pin number to track the button
- *pullupMode* - Whether the button is used as a pullup or not

**bool isDown()**
- *@returns* Whether the button is currently down or not

**int getPin()**
- *@returns* The pin number the button is registered to
