#include "walking_led.h"

WalkingLED::WalkingLED(uint32_t framerate)
    : Animation(framerate), _index(0)
{
}

void WalkingLED::show()
{
    FastLED.clear();
    _buffer[_index++ % _size] = CRGB::Red;
    FastLED.delay(1000 / _framerate);
    if (_index < _size)
        show();
}