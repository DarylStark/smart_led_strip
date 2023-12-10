#include "animation_displayer.h"

AnimationDisplayer::AnimationDisplayer(CRGB *buffer, uint32_t size)
    : _buffer(buffer), _size(size)
{
}

void AnimationDisplayer::show(Animation *animation)
{
    animation->set_details(_buffer, _size);
    animation->show();
}