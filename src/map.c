#include "map.h"
#include <stdlib.h>
#include <stdio.h>

t_map *map_init(SDL_Renderer *renderer, int width, int height) {
    t_map *map = malloc(sizeof(t_map));
    map->width = width;
    map->height = height;
    map->grid = malloc(width * sizeof(t_point *));
    for (int i = 0; i < width; i++) {
        map->grid[i] = malloc(height * sizeof(t_point));
    }
    // Initialize map grid here
    return map;
}

void map_draw(t_map *map, SDL_Renderer *renderer, t_player *player) {
    // Draw the map here
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            // Draw a rectangle for each cell in the grid
            SDL_Rect rect = {i * 20, j * 20, 20, 20};
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    // Draw the player here
    SDL_Rect player_rect = {player->x * 20, player->y * 20, 20, 20};
    SDL_RenderFillRect(renderer, &player_rect);
}

void map_free(t_map *map) {
    for (int i = 0; i < map->width; i++) {
        free(map->grid[i]);
    }
    free(map->grid);
    free(map);
}
