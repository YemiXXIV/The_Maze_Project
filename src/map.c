#include "map.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

t_map *map_init(SDL_Renderer *renderer, int width, int height) {
    t_map *map = malloc(sizeof(t_map));
    map->width = width;
    map->height = height;
    map->data = malloc(sizeof(t_map_data *) * width);
    for (int i = 0; i < width; i++) {
        map->data[i] = malloc(sizeof(t_map_data) * height);
    }
    map->floor = SDL_CreateTextureFromSurface(renderer, IMG_Load("floor.bmp"));
    map->ceiling = SDL_CreateTextureFromSurface(renderer, IMG_Load("ceiling.bmp"));
    map->walls = SDL_CreateTextureFromSurface(renderer, IMG_Load("wall.bmp"));
    return map;
}

void map_free(t_map *map) {
    for (int i = 0; i < map->width; i++) {
        free(map->data[i]);
    }
    free(map->data);
    SDL_DestroyTexture(map->floor);
    SDL_DestroyTexture(map->ceiling);
    SDL_DestroyTexture(map->walls);
    free(map);
}

void map_set_wall(t_map *map, int x, int y) {
    map->data[x][y] = MAP_WALL;
}

void map_unset_wall(t_map *map, int x, int y) {
    map->data[x][y] = MAP_SPACE;
}

int map_is_wall(t_map *map, int x, int y) {
    return map->data[x][y] == MAP_WALL;
}

void map_draw(t_map *map, SDL_Renderer *renderer, t_player *player) {
    for (int x = 0; x < map->width; x++) {
        for (int y = 0; y < map->height; y++) {
            SDL_Rect wall_rect = {x * 32, y * 32, 32, 32};
            SDL_Rect floor_rect = {x * 32, y * 32, 32, 32};
            if (map_is_wall(map, x, y)) {
                SDL_RenderCopy(renderer, map->walls, NULL, &wall_rect);
            } else {
                SDL_RenderCopy(renderer, map->floor, NULL, &floor_rect);
            }
        }
    }
    SDL_Rect player_rect = {player->x * 32, player->y * 32, 32, 32};
    SDL_RenderCopy(renderer, player->texture, NULL, &player_rect);
}
