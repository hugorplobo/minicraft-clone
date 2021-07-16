#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "../../utils/types.h"

void movePlayer(Player* player, Camera2D* camera);
void getPlayerInputs(Player* player);
void handlePlayerInputs(Player* player, Camera2D* camera);
void drawPlayer(Player* player, Texture* sprites);
void updatePlayer(Player* player);

#endif