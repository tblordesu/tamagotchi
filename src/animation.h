#ifndef ANIMATION_H
#define ANIMATION_H

#include <stdint.h>

#include "sprites.h"
#include "platform.h"

typedef struct {
    const Sprite ** frames;
    int framesCount;
    int currentFrame;

    uint32_t frameDuration;
    uint32_t lastSwitchTime;
} Animation;

extern Animation catIdleAnimation;
extern Animation catHappyAnimation;

extern const Sprite * catIdleAnimationSpriteList[];
extern const Sprite * catHappyAnimationSpriteList[];

void animationUpdate(Animation * animation, uint32_t nowTime);
void drawAnimation(int x, int y, Animation * animation);

#endif