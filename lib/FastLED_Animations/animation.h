#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <FastLED.h>

class Animation
{
protected:
    CRGB *_buffer;
    uint32_t _size;

public:
    void set_details(CRGB *buffer, uint32_t size);

    // Pure abstract functions
    virtual void set_next_frame() = 0;
    virtual void setup() = 0;
};

#endif /* __ANIMATION_H__ */