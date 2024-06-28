#include "map.h"
#include "player.h"
#include "SDL.h"
#include "SDL_image.h"

t_map *map_init(SDL_Renderer *renderer, int width, int height) {
    t_map *map = malloc(sizeof(t_map));
    map->width = width;
    map->height = height;
    map->data = malloc(width * sizeof(t_map_data *));
    for (int i = 0; i < width; i++) {
        map->data[i] = malloc(height * sizeof(t_map_data));
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
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            if (map->data[i][j] == MAP_WALL) {
                SDL_Rect wall_rect = {i * 32, j * 32, 32, 32};
                SDL_RenderCopy(renderer, map->walls, NULL, &wall_rect);
            } else {
                SDL_Rect floor_rect = {i * 32, j * 32, 32, 32};
                SDL_RenderCopy(renderer, map->floor, NULL, &floor_rect);
            }
        }
    }
    // draw player
    SDL_Rect player_rect = {player->x * 32, player->y * 32, 32, 32};
    // assuming player has a SDL_Texture member called 'texture'
    SDL_RenderCopy(renderer, player->texture, NULL, &player_rect);
}
