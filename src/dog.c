#include "pet.h"

Pet Dog = {
    .type = DOG,
    .state = IDLE,
    .hunger = 4,
    .happiness = 6,
    .health = 8,
    .energy = 4,
    .animations = &dogAnimations
};

const PetAnimations catAnimations  = {
    .idle = NULL,       // потом будет &dogIdleAnimation
    .happy = NULL,      // потом будет &catHappyAnimation,
    .sick = NULL,                   //временно
    .eating = NULL,                 //временно
    .sleeping = NULL                //временно
};