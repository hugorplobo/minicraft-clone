#ifndef TERRAIN_GENERATION_H
#define TERRAIN_GENERATION_H

#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "../../utils/types.h"
#include "../../utils/constants.h"

TerrainTile* generateTerrain() {
    Image perlinNoise = GenImagePerlinNoise(200, 200, GetRandomValue(0, 10000), GetRandomValue(0, 10000), 2);
    Color* mapColors = LoadImageColors(perlinNoise);
    TerrainTile* mapTiles = (TerrainTile*) malloc(sizeof(TerrainTile) * 200 * 200);

    for(int i = 0; i < 200 * 200; i++) {
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
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            if(!(i * RESOLUTION <= camera->target.x + WIDTH && 
                i * RESOLUTION >= camera->target.x - WIDTH &&
                j * RESOLUTION <= camera->target.y + HEIGHT &&
                j * RESOLUTION >= camera->target.y - HEIGHT)) continue;

            Color tileColor;

            switch(mapTiles[i * 200 + j]) {
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