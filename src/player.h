#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

void player_init(t_player *player, int x, int y, int direction);
void player_move(t_player *player, t_map *map, int dx, int dy);

#endif  // PLAYER_H
