#ifndef PET_H
#define PET_H

#include "animation.h"

typedef enum {
    IDLE = 0,
    HAPPY,
    SICK,
    EATING,
    SLEEPING
} PetState;

typedef enum {
    CAT = 0,
    DOG
} PetType;

typedef struct {
    PetType type;
    PetState state;
    int hunger;
    int happiness;
    int health;
    int energy;

    const PetAnimations * animations;
} Pet;

typedef struct {
    const Animation * idle;
    const Animation * happy;
    const Animation * sick;
    const Animation * eating;
    const Animation * sleeping;
} PetAnimations;

extern Pet Cat;
extern Pet Dog;

extern const PetAnimations catAnimations;
extern const PetAnimations dogAnimations;

#endif