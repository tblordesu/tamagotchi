#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>

typedef enum {
    BUTTON_Q = 0,
    BUTTON_W,
    BUTTON_E,
    BUTTON_COUNT
} Button;

int platformInit();
void platformShutdown();

int platformRunning();
void platformPollEvents();

int platformButtonPressed(Button button);
int platformButtonReleased(Button button);
int platformButtonHeld(Button button);

uint32_t platformGetTimeMs();
void platformDelay(uint32_t ms);

void platformPresent();


#endif