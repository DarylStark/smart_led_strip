#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 100
#define DATA_PIN 26

CRGB leds[NUM_LEDS];
#include "fire_effect.h"

void setup()
{
    Serial.begin(115200);
    delay(3000);
    FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(5);
    gPal = HeatColors_p;
}

void loop()
{
    // Add entropy to random number generator; we use a lot of it.
    random16_add_entropy(random());

    Fire2012(); // run simulation frame, using palette colors

    FastLED.show(); // display this frame
    FastLED.delay(1000 / FRAMES_PER_SECOND);
    Serial.println('.');
}
