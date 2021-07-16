#ifndef TERRAIN_GENERATION_H
#define TERRAIN_GENERATION_H

#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "../../utils/types.h"
#include "../../utils/constants.h"

TerrainTile* generateTerrain() {
    srand(time(0));
    Image perlinNoise = GenImagePerlinNoise(100, 100, rand() % 100, rand() % 100, 3);
    Color* mapColors = LoadImageColors(perlinNoise);
    TerrainTile* mapTiles = (TerrainTile*) malloc(sizeof(TerrainTile) * 100 * 100);

    for(int i = 0; i < 100 * 100; i++) {
        int sumColor = mapColors[i].r + mapColors[i].g + mapColors[i].b;

        if(sumColor <= 255)
            mapTiles[i] = DIRT;
        else if(sumColor <= 510)
            mapTiles[i] = GRASS;
        else
            mapTiles[i] = STONE;
    }

    UnloadImageColors(mapColors);
    return mapTiles;
}

void drawTerrain(TerrainTile* mapTiles, Camera2D* camera) {
    Vector2 initBorder, endBorder;

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            Color tileColor;

            switch (mapTiles[i * 100 + j]) {
                case DIRT:
                    tileColor = BROWN;
                    break;
                case GRASS:
                    tileColor = DARKGREEN;
                    break;
                case STONE:
                    tileColor = GRAY;
                    break;
            }

            DrawRectangle(i * RESOLUTION, j * RESOLUTION, RESOLUTION, RESOLUTION, tileColor);
        }
    }
}

#endif