#include <string.h>
#include "graphics.h"

uint8_t framebuffer[FRAMEBUFFER_SIZE];

void graphicsClear() {
    memset(framebuffer, 0, sizeof(framebuffer));
}

void setPixel(int x, int y, int val) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        return;

    int pixel = y * SCREEN_WIDTH + x;
    int byte_index = pixel / 8;
    int bit_index = pixel % 8;

    if (val) 
        framebuffer[byte_index] |= (1u << bit_index);
    else
        framebuffer[byte_index] &= ~(1u << bit_index);
}

int getPixel(int x, int y) {
    if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        return 1;

    int pixel = y * SCREEN_WIDTH + x;
    int byte_index = pixel / 8;
    int bit_index = pixel % 8;

    return (framebuffer[byte_index] >> bit_index) & 1u;
}

void drawSprite(int x, int y, const Sprite *sprite) {
    //int start_draw_x, start_draw_y = x, y;

    for (int draw_y = 0; draw_y < sprite->height; ++draw_y) {
        for (int draw_x = 0; draw_x < sprite->width; ++draw_x) {
            int pixel = draw_y * sprite->width + draw_x;

            int byte_index = pixel / 8;
            int bit_index = pixel % 8;

            int val = (sprite->data[byte_index] >> bit_index) & 1u;
            if (val)
                setPixel(x + draw_x, y + draw_y, 1);
        }
    }
}