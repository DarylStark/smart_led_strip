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
    if (_animation == nullptr)
        return;

    _animation->setup();
    _is_setup = true;
}

void AnimationDisplayer::_loop_delay()
{
    if (_framerate > 0)
        FastLED.delay(1000 / _framerate);
    else
        FastLED.delay(0);
}

void AnimationDisplayer::loop()
{
    _loop_delay();
    if (_animation == nullptr)
        return;

    if (!_is_setup)
        setup();

    _animation->set_next_frame();
}

void AnimationDisplayer::_loop_thread()
{
    while (true)
    {
        loop();
    }
}

void AnimationDisplayer::start_loop_thread()
{
    std::thread loop_thread(
        std::bind(&AnimationDisplayer::_loop_thread, this));
    loop_thread.detach();
}