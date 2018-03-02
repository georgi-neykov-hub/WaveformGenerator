#include <Arduino.h>
#include <TFT.h> // Hardware-specific library
#include <SPI.h>
#include <JoystickPad.h>


#define TFT_PIN_CS   A2
#define TFT_PIN_RS   A0
#define TFT_PIN_RST  A1  

TFT TFTscreen = TFT(TFT_PIN_CS, TFT_PIN_RS, TFT_PIN_RST);
JoystickPad joyStickPad = JoystickPad(A8, A6, A3);

void onXAxisChange(int8_t value){
    Serial.print("X:");
    Serial.println(value);
}

void onYAxisChange(int8_t value){
    Serial.print("Y:");
    Serial.println(value);
}

void setup() {
  Serial.begin(56200);
  Serial.println("Starting");
  joyStickPad.setAxisXChangeListener(&onXAxisChange);
  joyStickPad.setAxisYChangeListener(&onYAxisChange);
  
  joyStickPad.begin();
  TFTscreen.begin();

  TFTscreen.background(0, 0, 0);

  TFTscreen.stroke(255,0,255);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Waveform",0,0);
  TFTscreen.setTextSize(3);
}

void loop() {
    
    joyStickPad.loop();
    
}