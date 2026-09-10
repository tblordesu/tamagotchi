#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "platform.h"
#include "graphics.h"

#define SCALE 8

static SDL_Window * window = NULL;
static SDL_Renderer * renderer = NULL;

static int running = 1;

static int buttonPressed[BUTTON_COUNT];
static int buttonReleased[BUTTON_COUNT];
static int buttonHeld[BUTTON_COUNT];

static int getButtonFromScancode(SDL_Scancode key) {
    switch (key) {
        case SDL_SCANCODE_Q:
            return BUTTON_Q;

        case SDL_SCANCODE_W:
            return BUTTON_W;

        case SDL_SCANCODE_E:
            return BUTTON_E;

        default:
            return -1;
    }
}

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

    for (int i = 0; i < BUTTON_COUNT; ++i) {
        buttonPressed[i] = 0;
        buttonReleased[i] = 0;
    }

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            running = 0;

        else if (event.type == SDL_KEYDOWN) {

            if (event.key.repeat != 0)
                continue;

            int button = getButtonFromScancode(event.key.keysym.scancode);

            if(button >= 0) {
                buttonPressed[button] = 1;
                buttonHeld[button] = 1;
            }

            if (event.key.keysym.sym == SDLK_ESCAPE)
                running = 0;
        }

        else if (event.type == SDL_KEYUP) {

            int button = getButtonFromScancode(event.key.keysym.scancode);

            if (button >= 0) {
                buttonReleased[button] = 1;
                buttonHeld[button] = 0;
            }
        }
    }
}

int platformButtonPressed(Button button) {
    if (button < 0 || button >= BUTTON_COUNT)
        return 0;

    return buttonPressed[button];
}

int platformButtonReleased(Button button) {
    if (button <0 || button >= BUTTON_COUNT)
        return 0;

    return buttonReleased[button];
}

int platformButtonHeld (Button button) {
    if (button < 0 || button >= BUTTON_COUNT)
        return 0;

    return buttonHeld[button];
}

uint32_t platformGetTimeMs () {
    return SDL_GetTicks();
}

void platformDelay (uint32_t ms) {
    SDL_Delay(ms);
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

    running = 0;
}