#ifndef TYPES_H
#define TYPES_H

#include <raylib.h>

// Terrain Related
typedef enum {
    DIRT,
    GRASS,
    STONE
} TerrainTile;

// Player Related
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