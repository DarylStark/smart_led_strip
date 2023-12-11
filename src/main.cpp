#include <Arduino.h>
#include <FastLED.h>
#include <animation_displayer.h>
#include <walking_led.h>
#include <progress.h>

#define NUM_LEDS 100
#define DATA_PIN 26

CRGB leds[NUM_LEDS];
AnimationDisplayer ad(leds, NUM_LEDS, 60);

// Animations
Progress progress;

void setup()
{
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(5);
    FastLED.clear();
    FastLED.show();

    ad.start_loop_thread();
    ad.set_animation(&progress);
    delay(5000);
}

void loop()
{
    progress.set_progress(10);
    delay(500);
}
