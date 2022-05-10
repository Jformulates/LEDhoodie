#include "Arduino.h"

class PurpleG {
  public:
  PurpleG(){
  }
  void runPattern();
  private:
  };

void PurpleG::runPattern() {
static uint8_t paletteIndex = 0;

EVERY_N_MILLISECONDS(15){
    paletteIndex++;
  }

CRGBPalette16 purplePalette = CRGBPalette16 (
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    
    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::Linen,
    CRGB::Linen,
    
    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::DarkViolet,
    CRGB::DarkViolet,

    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::Linen,
    CRGB::Linen
);
   fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, purplePalette, 255, LINEARBLEND);

   btn.tick();
  FastLED.show();
  
}
