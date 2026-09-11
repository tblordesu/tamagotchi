#include "pet.h"

Pet Cat = {
    .type = CAT,
    .state = IDLE,
    .hunger = 4,
    .happiness = 6,
    .health = 8,
    .energy = 4,
    .animations = &catAnimations
};

const PetAnimations catAnimations  = {
    .idle = &catIdleAnimation,
    .happy = &catHappyAnimation,
    .sick = NULL,                   //временно
    .eating = NULL,                 //временно
    .sleeping = NULL                //временно
};