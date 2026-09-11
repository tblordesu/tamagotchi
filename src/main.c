#include "graphics.h"
#include "sprites.h"
#include "platform.h"
#include "animation.h"

static int switchAnimation = 0;

int main(int argc, char **args) {
    if (!platformInit())
        return 1;

    while (platformRunning()) {
        platformPollEvents();

        uint32_t nowTime = platformGetTimeMs();

        if(platformButtonPressed(BUTTON_Q))
            switchAnimation = 1;

        else if(platformButtonPressed(BUTTON_W)) 
            switchAnimation = 0;

        if(switchAnimation) {
            animationUpdate(&catIdleAnimation, nowTime);
            graphicsClear();
            drawAnimation(40, 10, &catIdleAnimation);
        }

        else {
            animationUpdate(&catHappyAnimation, nowTime);
            graphicsClear();
            drawAnimation(40, 10, &catHappyAnimation);
        }    
        
        platformPresent();
        
        platformDelay(16);
    }

    platformShutdown();
    return 0;
}