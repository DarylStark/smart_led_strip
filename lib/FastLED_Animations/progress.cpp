#include "progress.h"

Progress::Progress()
    : _progress(0)
{
}

void Progress::setup()
{
}

void Progress::set_next_frame()
{
    double percentage = static_cast<double>(_progress) / 100;
    double num_leds = _size * percentage;

    Serial.println(num_leds);

    FastLED.clear(); // TODO: Make this a protected member function of `Animation`
    for (uint32_t index = 0; index < num_leds; index++)
        _buffer[index] = CRGB::Green;
}

void Progress::set_progress(uint8_t progress)
{
    if (progress <= 100)
        _progress = progress;
}

uint8_t Progress::get_progress() const
{
    return _progress;
}