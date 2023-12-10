#include "animation.h"

void Animation::set_details(CRGB *buffer, uint32_t size)
{
    _buffer = buffer;
    _size = size;
}