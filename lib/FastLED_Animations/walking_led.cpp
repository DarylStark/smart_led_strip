#include "walking_led.h"

WalkingLED::WalkingLED()
    : _index(0)
{
}

void WalkingLED::setup()
{
}

void WalkingLED::set_next_frame()
{
    _buffer[(_index - 1) % _size] = CRGB::Black;
    _buffer[_index++ % _size] = CRGB::Red;
}