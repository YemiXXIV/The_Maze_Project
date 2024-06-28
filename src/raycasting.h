#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "map.h"
#include "player.h"

void raycasting_init(t_player *player);
void raycasting_draw_walls(SDL_Renderer *renderer, t_player *player, t_map *maze);

#endif  // RAYCASTING_H
