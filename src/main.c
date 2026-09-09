#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "graphics.h"
#include "sprites.h"
#include "platform.h"

int main(int argc, char **args) {
    if (!platformInit())
        return 1;

    while (platformRunning()) {
        platformPollEvents();

        graphicsClear();

        drawSprite(5, 5, &petIdle);

        platformPresent();
    }

    platformShutdown();
    return 0;
}