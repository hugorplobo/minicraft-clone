#include <raylib.h>
#include "../../utils/types.h"
#include "../../utils/constants.h"

int framesCounter = 0, framesSpeed = 6, currentFrame = 0;
Rectangle frameRec = { 0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE };

void movePlayer(Player* player, Camera2D* camera) {
    float deltaTime = GetFrameTime();
    player->pos.x += PLAYER_SPEED * deltaTime * player->velocity.x;
    player->pos.y += PLAYER_SPEED * deltaTime * player->velocity.y;

    camera->target = (Vector2){ player->pos.x + PLAYER_SPRITE_SIZE / 2.0, player->pos.y + PLAYER_SPRITE_SIZE / 2.0 };
}

void getPlayerInputs(Player* player) {
    if(IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
        player->direction = RIGHT;
        player->velocity.x = 1;
        return;
    } else if(IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
        player->direction = LEFT;
        player->velocity.x = -1;
        return;
    } else if(IsKeyDown(KEY_UP) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_DOWN)) {
        player->direction = UP;
        player->velocity.y = -1;
        return;
    } else if(IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_RIGHT)) {
        player->direction = DOWN;
        player->velocity.y = 1;
        return;
    }
}

void handlePlayerInputs(Player* player, Camera2D* camera) {
    getPlayerInputs(player);
    
    if(!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT))
        player->velocity.x = 0;
    if(!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN))
        player->velocity.y = 0;

    if(player->velocity.x != 0 || player->velocity.y != 0)
        movePlayer(player, camera);
}

void drawPlayer(Player* player, Texture* sprites) {
    frameRec.x = player->direction * PLAYER_SPRITE_SIZE;
    DrawTextureRec(*sprites, frameRec, player->pos, WHITE);
}

void updatePlayer(Player* player) {
    if(player->velocity.x != 0 || player->velocity.y != 0) {
        framesCounter++;
        if(framesCounter >= 60 / framesSpeed) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;
        }
    } else {
        framesCounter = 0;
        currentFrame = 0;
    }

    frameRec.y = currentFrame * PLAYER_SPRITE_SIZE; 
}
