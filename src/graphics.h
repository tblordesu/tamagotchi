#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define FRAMEBUFFER_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 8)

extern uint8_t framebuffer[FRAMEBUFFER_SIZE];

typedef struct {
    int width;
    int height;
    const uint8_t *data;
} Sprite;

extern const uint8_t petIdleSprite[];

extern const Sprite petIdle;

void graphicsClear();
void setPixel(int x, int y, int val);
int getPixel(int x, int y);
void drawSprite(int x, int y, const Sprite *sprite);

#endif