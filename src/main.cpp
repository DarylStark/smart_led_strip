#include <Arduino.h>
#include <FastLED.h>
#include <animation_displayer.h>
#include <walking_led.h>
#include <progress.h>

#define NUM_LEDS 100
#define DATA_PIN 26

CRGB leds[NUM_LEDS];
AnimationDisplayer ad(leds, NUM_LEDS, 100);

// Animations
WalkingLED *wl = new WalkingLED;

void setup()
{
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(5);
    FastLED.clear();

    ad.set_animation(wl);
}

void loop()
{
    ad.loop();
}
