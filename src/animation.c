#include "animation.h"

Animation catIdleAnimation = {
    .frames = catIdleAnimationSpriteList,
    .framesCount = 2,
    .currentFrame = 0,
    .frameDuration = 400,
    .lastSwitchTime = 0
};

Animation catHappyAnimation = {
    .frames = catHappyAnimationSpriteList,
    .framesCount = 2,
    .currentFrame = 0,
    .frameDuration = 400,
    .lastSwitchTime = 0
};

const Sprite * catIdleAnimationSpriteList[] = {
    &catIdle1,
    &catIdle2
};

const Sprite * catHappyAnimationSpriteList[] = {
    &catHappy1,
    &catHappy2
};

void animationUpdate (Animation * animation, uint32_t nowTime) {
    if (nowTime - animation->lastSwitchTime >= animation->frameDuration) {
        animation->currentFrame++;
        
        if(animation->currentFrame >= animation->framesCount)
            animation->currentFrame = 0;

        animation->lastSwitchTime = nowTime;
    }
}

void drawAnimation (int x, int y, Animation * animation) {
    drawSprite(x, y, animation->frames[animation->currentFrame]);
}