#include "graphics.h"
#include "sprites.h"
#include "platform.h"
#include "animation.h"

static int switchSprite = 0;

int main(int argc, char **args) {
    if (!platformInit())
        return 1;

    while (platformRunning()) {
        platformPollEvents();

        uint32_t nowTime = platformGetTimeMs();

        animationUpdate(&catIdleAnimation, nowTime);

        graphicsClear();
        
        drawAnimation(40, 10, &catIdleAnimation);
        
        platformPresent();
        
        platformDelay(16);
    }

    platformShutdown();
    return 0;
}