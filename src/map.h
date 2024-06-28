#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>

typedef struct {
    int width;
    int height;
    char **data;
} t_map;

t_map *map_init(SDL_Renderer *renderer, int width, int height);

#endif  // MAP_H
