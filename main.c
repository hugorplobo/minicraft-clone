#include <raylib.h>
#include "utils/constants.h"
#include "utils/types.h"

#include "entities/player/player.h"

int main() {
    InitWindow(WIDTH, HEIGHT, "Minicraft");

    Player player = { { WIDTH / 2.0, HEIGHT / 2.0 }, { 0, 0 } };

    while(!WindowShouldClose()) {

        double deltaTime = GetFrameTime();

        handlePlayerInputs(&player);

        if(player.direction.x != 0 || player.direction.y != 0)
            movePlayer(&player, deltaTime);

        BeginDrawing();

            ClearBackground(BLACK);
            
            DrawRectangleV(player.pos, (Vector2){ RESOLUTION, RESOLUTION }, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}