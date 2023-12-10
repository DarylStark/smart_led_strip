#ifndef __PROGRESS_H__
#define __PROGRESS_H__

#include "animation.h"

class Progress : public Animation
{
private:
    uint8_t _progress;

public:
    Progress();
    void setup() override;
    void set_next_frame() override;

    void set_progress(uint8_t progress);
    uint8_t get_progress() const;
};

#endif /* __PROGRESS_H__ */