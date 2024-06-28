#ifndef MAP_H
#define MAP_H

#include "types.h"
#include <SDL2/SDL.h>

t_map *map_init(SDL_Renderer *renderer, int width, int height);
void map_draw(t_map *map, SDL_Renderer *renderer, t_player *player);
void map_free(t_map *map);

#endif  // MAP_H
