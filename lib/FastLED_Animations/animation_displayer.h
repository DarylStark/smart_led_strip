#ifndef __ANIMATIONDISPLAYER_H__
#define __ANIMATIONDISPLAYER_H__

#include <FastLED.h>

#include "animation.h"

class AnimationDisplayer
{
private:
    CRGB *_buffer;
    uint32_t _size;
    Animation *_animation;
    uint32_t _framerate;
    bool _is_setup;

public:
    AnimationDisplayer(CRGB *buffer, uint32_t size, uint32_t framerate);
    void set_animation(Animation *animation);

    void setup();
    void loop();
};

#endif /* __ANIMATIONDISPLAYER_H__ */