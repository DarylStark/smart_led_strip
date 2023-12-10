#include <Arduino.h>
#include <FastLED.h>
#include <animation_displayer.h>
#include <walking_led.h>

#define NUM_LEDS 100
#define DATA_PIN 26

CRGB leds[NUM_LEDS];
AnimationDisplayer ad(leds, NUM_LEDS);

void setup()
{
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(5);

    Animation *ani = new WalkingLED(60);
    leds[0] = CRGB::Green;
    ad.show(ani);
    delete ani;
}

void loop()
{
    delay(1000);
}
