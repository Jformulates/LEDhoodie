#include <FastLED.h>
#include <OneButton.h>

#define NUM_LEDS  32
#define LED_PIN   2
#define BTN_PIN   3

CRGB leds[NUM_LEDS];
uint8_t patternCounter = 0;
bool isRunning = false;

// Push button connected between pin 7 and GND (no resistor required)
OneButton btn = OneButton(BTN_PIN, true, true);

#include "MovingDot.h"
#include "RainbowBeat.h"
#include "RedWhiteBlue.h"
#include "PurpleG.h"
#include "Pacifica.h"
#include "Blur.h"


void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  Serial.begin(57600);

  btn.attachClick(nextPattern);
}

void loop() {
  
  switch (patternCounter) {
    case 0:
      runPurpleG();
      break;
    case 1:
      runPacifica();
      break;
    case 2:
      runRedWhiteBlue();
      break;
    case 3: 
      runMovingDot();
      break;
    case 4:
      runRainbowBeat();
      break;
    case 5:
     runBlur();
     break;

  }
}

void nextPattern() {
  isRunning = false;
  patternCounter = (patternCounter + 1) % 6;
}

void runMovingDot(){
  isRunning = true;
  MovingDot movingDot = MovingDot();
  while(isRunning) movingDot.runPattern();
}

void runRainbowBeat(){
  isRunning = true;
  RainbowBeat rainbowBeat = RainbowBeat();
  while(isRunning) rainbowBeat.runPattern();
}

void runRedWhiteBlue(){
  isRunning = true;
  RedWhiteBlue redWhiteBlue = RedWhiteBlue();
  while(isRunning) redWhiteBlue.runPattern();
}

void runPurpleG() {
  isRunning = true;
  PurpleG purpleG = PurpleG();
  while(isRunning) purpleG.runPattern();
}

void runPacifica(){
  isRunning = true;
  Pacifica pacifica = Pacifica();
  while(isRunning) pacifica.runPattern();
}

void runBlur(){
  isRunning = true;
  Blur blur = Blur();
  while(isRunning) blur.runPattern();
}
