#include <JoystickPad.h>

JoystickPad::JoystickPad(uint8_t axisXPin, uint8_t axisYPin, uint8_t buttonPin):
axisXPin(axisXPin), axisYPin(axisYPin), buttonPin(buttonPin), 
axisXListener(NULL), axisYListener(NULL){

}

void JoystickPad::setOnClickListener(OnClickListener listener){

}
void JoystickPad::setAxisXChangeListener(OnAxisChangeListener listener){
    axisXListener = listener;
}
void JoystickPad::setAxisYChangeListener(OnAxisChangeListener listener){
    axisYListener = listener;
}

void JoystickPad::begin(){
    analogScanner.beginScanning();
    int scanOrder[] = {axisXPin, axisYPin};
    analogScanner.setScanOrder(2, scanOrder);
    analogScanner.beginScanning();
    delay(1);
}

int8_t mapValue(int analogValue) {
    if(analogValue > 550) {return 1;}
    else if(analogValue < 450) {return -1;}
    else {return 0;}
}

void JoystickPad::loop(){
    uint8_t xVal = mapValue(analogScanner.getValue(axisXPin));
    if(xVal != axisXPin){
        axisXPin = xVal;
        if(axisXListener != NULL) {
            axisXListener(axisXPin);
        }
    }

    int8_t yVal = mapValue(analogScanner.getValue(axisYPin));
    if(yVal != axisYPin){
        axisYPin = yVal;
        if(axisYListener != NULL) {
            axisYListener(axisYPin);
        }
    }
}

