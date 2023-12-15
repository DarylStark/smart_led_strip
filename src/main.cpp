#include <Arduino.h>
#include <FastLED.h>
#include <animation_displayer.h>
#include <walking_led.h>
#include <progress.h>

#include <WiFiManager.h>
#include <ESPAsyncWebServer.h>

#define NUM_LEDS 100
#define DATA_PIN 26

CRGB leds[NUM_LEDS];
AnimationDisplayer ad(leds, NUM_LEDS, 60);
AsyncWebServer web(80);

// Animations
Progress progress;

void progress_up(AsyncWebServerRequest *request)
{
    progress.set_progress(progress.get_progress() + 1);
    request->send(200, "text/html", "<p>Done</p>");
}

void progress_down(AsyncWebServerRequest *request)
{
    progress.set_progress(progress.get_progress() - 1);
    request->send(200, "text/html", "<p>Done</p>");
}

void setup()
{
    Serial.begin(115200);

    WiFiManager wm;
    if (wm.autoConnect("Smart LED Strip"))
    {
        // Set up the FastLED strip
        FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
        FastLED.setBrightness(5);
        FastLED.clear();
        FastLED.show();

        // Start the AnimationDisplayer loop
        ad.start_loop_thread();
        ad.set_animation(&progress);

        // Create the web application
        web.on("/up", progress_up);
        web.on("/down", progress_down);
        web.begin();
    }
}

void loop()
{
    delay(500);
}
