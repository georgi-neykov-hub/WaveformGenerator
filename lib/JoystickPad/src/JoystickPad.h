#ifndef JOYSTICKPAD_H
#define JOYSTICKPAD_H

#include <Arduino.h>
#include <AnalogScanner.h>


typedef void (*OnClickListener)();
typedef void (*OnAxisChangeListener)(int8_t);

class JoystickPad {
    private:
        uint8_t axisXPin;
        uint8_t axisYPin;
        uint8_t buttonPin;

        int8_t axisXValue;
        int8_t axisYValue;
        AnalogScanner analogScanner;
        OnAxisChangeListener axisXListener;
        OnAxisChangeListener axisYListener;

    public: 
    JoystickPad(uint8_t axisXPin, uint8_t axisYPin, uint8_t buttonPin);

    void setOnClickListener(OnClickListener listener);
    void setAxisXChangeListener(OnAxisChangeListener listener);
    void setAxisYChangeListener(OnAxisChangeListener listener);
    void begin();
    void loop();
};









#endif //JOYSTICKPAD_H