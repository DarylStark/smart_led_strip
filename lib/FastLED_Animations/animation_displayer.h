#ifndef __ANIMATIONDISPLAYER_H__
#define __ANIMATIONDISPLAYER_H__

#include <FastLED.h>

#include "animation.h"

class AnimationDisplayer
{
private:
    CRGB *_buffer;
    uint32_t _size;

public:
    AnimationDisplayer(CRGB *buffer, uint32_t size);
    void show(Animation *animation);
};

#endif /* __ANIMATIONDISPLAYER_H__ */