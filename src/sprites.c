#include "sprites.h"

const uint8_t petIdleSprite[] = {
    0b00000000,
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10100101,
    0b01011010,
    0b00111100
};

const Sprite petIdle = {
    .width = 8,
    .height = 8,
    .data = petIdleSprite
};