#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL_render.h>
#include "player.h"
#include "map.h"

void raycasting_draw_walls(SDL_Renderer *renderer, t_player *player, t_map *maze);

#endif  // RAYCASTING_H
