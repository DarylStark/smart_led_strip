#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <FastLED.h>

class Animation
{
protected:
    CRGB *_buffer;
    uint32_t _size;
    uint32_t _framerate;

public:
    Animation(uint32_t framerate);
    void set_details(CRGB *buffer, uint32_t size);
    virtual void show() = 0;
};

#endif /* __ANIMATION_H__ */