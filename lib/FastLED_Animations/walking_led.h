#ifndef __WALKING_LED_H__
#define __WALKING_LED_H__

#include "animation.h"

class WalkingLED : public Animation
{
private:
    uint32_t _index;

public:
    WalkingLED();
    void setup() override;
    void set_next_frame() override;
};

#endif /* __WALKING_LED_H__ */