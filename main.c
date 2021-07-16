#include <raylib.h>
#include "utils/constants.h"
#include "utils/types.h"

#include "entities/player/player.h"

int main() {
    InitWindow(WIDTH, HEIGHT, "Minicraft");
    SetTargetFPS(60);

    Player player = { { WIDTH / 2.0, HEIGHT / 2.0 }, RIGHT, { 0, 0 } };
    Texture playerSpriteSheet = LoadTexture("../assets/player/player.png");

    while(!WindowShouldClose()) {
        updatePlayer(&player);
        handlePlayerInputs(&player);

        BeginDrawing();

            ClearBackground(BLACK);
            drawPlayer(&player, &playerSpriteSheet);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}