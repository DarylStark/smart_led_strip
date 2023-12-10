#include "animation.h"

Animation::Animation(uint32_t framerate)
    : _framerate(framerate)
{
}

void Animation::set_details(CRGB *buffer, uint32_t size)
{
    _buffer = buffer;
    _size = size;
}