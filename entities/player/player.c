#include <raylib.h>
#include "../../utils/types.h"
#include "../../utils/constants.h"

void movePlayer(Player* player, double deltaTime) {
    player->pos.x += PLAYER_SPEED * deltaTime * player->direction.x;
    player->pos.y += PLAYER_SPEED * deltaTime * player->direction.y;
}

void handlePlayerInputs(Player* player) {
    if(IsKeyDown(KEY_RIGHT)) 
        player->direction.x = 1;
    else if(IsKeyDown(KEY_LEFT))
        player->direction.x = -1;
    else
        player->direction.x = 0;

    if(IsKeyDown(KEY_UP))
        player->direction.y = -1;
    else if(IsKeyDown(KEY_DOWN))
        player->direction.y = 1;
    else
     player->direction.y = 0;
}