#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "../../utils/types.h"

void movePlayer(Player* player);
void getPlayerInputs(Player* player);
void handlePlayerInputs(Player* player);
void drawPlayer(Player* player, Texture* sprites);
void updatePlayer(Player* player);

#endif