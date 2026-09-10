#include "graphics.h"
#include "sprites.h"
#include "platform.h"

static int switchSprite = 0;

int main(int argc, char **args) {
    if (!platformInit())
        return 1;

    while (platformRunning()) {
        platformPollEvents();
        
        platformPresent();
        
        platformDelay(16);
    }

    platformShutdown();
    return 0;
}