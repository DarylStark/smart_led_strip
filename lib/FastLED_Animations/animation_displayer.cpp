#include "animation_displayer.h"

AnimationDisplayer::AnimationDisplayer(CRGB *buffer, uint32_t size, uint32_t framerate)
    : _buffer(buffer), _size(size), _framerate(framerate), _is_setup(false)
{
}

void AnimationDisplayer::set_animation(Animation *animation)
{
    animation->set_details(_buffer, _size);
    _animation = animation;
    _is_setup = false;
}

void AnimationDisplayer::setup()
{
    _animation->setup();
    _is_setup = true;
}

void AnimationDisplayer::loop()
{
    if (!_is_setup)
        setup();

    _animation->set_next_frame();
    FastLED.delay(1000 / _framerate);
}