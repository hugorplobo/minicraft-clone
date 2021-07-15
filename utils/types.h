#ifndef TYPES_H
#define TYPES_H

#include <raylib.h>

typedef enum {
    RIGHT,
    DOWN,
    UP,
    LEFT
} PlayerDirection;

typedef struct {
    Vector2 pos;
    PlayerDirection direction;
    Vector2 velocity;
} Player;

#endif