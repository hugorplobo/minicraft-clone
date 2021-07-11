#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "../../utils/types.h"

void movePlayer(Player* player, double deltaTime);
void handlePlayerInputs(Player* player);

#endif