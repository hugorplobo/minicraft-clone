#include <raylib.h>
#include "utils/constants.h"
#include "utils/types.h"

#include "enviroment/terrain/terrainGeneration.h"
#include "entities/player/player.h"

int main() {
    InitWindow(WIDTH, HEIGHT, "Minicraft");
    SetTargetFPS(60);

    TerrainTile* map = generateTerrain();

    Player player = { { WIDTH / 2.0, HEIGHT / 2.0 }, RIGHT, { 0, 0 } };
    Texture playerSpriteSheet = LoadTexture("../assets/player/player.png");

    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.pos.x + PLAYER_SPRITE_SIZE / 2.0, player.pos.y + PLAYER_SPRITE_SIZE / 2.0 };
    camera.offset = (Vector2){ WIDTH / 2.0, HEIGHT / 2.0 };
    camera.rotation = 0;
    camera.zoom = 1;

    while(!WindowShouldClose()) {
        updatePlayer(&player);
        handlePlayerInputs(&player, &camera);

        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode2D(camera);
                drawTerrain(map, &camera);
                drawPlayer(&player, &playerSpriteSheet);
            EndMode2D();

            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}