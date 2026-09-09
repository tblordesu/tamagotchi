#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "platform.h"
#include "graphics.h"

#define SCALE 5

static SDL_Window * window = NULL;
static SDL_Renderer * renderer = NULL;

static int running = 1;

int platformInit() {
    SDL_SetMainReady();

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL Init Error: %s", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow(
        "Tamagotchi",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH * SCALE,
        SCREEN_HEIGHT * SCALE,
        0
    );

    if (window == NULL) {
        SDL_Log("SDL Create Window Error: %s", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (renderer == NULL) {
        SDL_Log("SDL Create Renderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        window = NULL;
        SDL_Quit();
        return 0;
    }
    return 1;
}

int platformRunning() {
    return running;
}

void platformPollEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            running = 0;
    }
}


void platformPresent () {
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);

    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            if (getPixel(x, y)) {
                SDL_Rect pixel = {
                    .x = x * SCALE,
                    .y = y * SCALE,
                    .w = SCALE,
                    .h = SCALE
                };

                SDL_RenderFillRect(renderer, &pixel);
            }
        }
    }    
    SDL_RenderPresent(renderer);
}

void platformShutdown() {
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window != NULL) {
        SDL_DestroyWindow(window);
        window = NULL;
    }

    SDL_Quit();
}