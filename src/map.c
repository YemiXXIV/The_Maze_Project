#include "map.h"
#include <stdlib.h>
#include <string.h>

t_map *map_init(SDL_Renderer *renderer, int width, int height) {
    t_map *maze = malloc(sizeof(t_map));
    maze->width = width;
    maze->height = height;
    maze->data = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze->data[i] = malloc(width * sizeof(char));
    }
    // Initialize map data here
    return maze;
}
