#ifndef MAP_H
#define MAP_H

typedef struct {
    SDL_Texture *floor;
    SDL_Texture *ceiling;
    SDL_Texture *walls;
} t_map;

void map_init(t_map *map, SDL_Renderer *renderer);
void map_draw(t_map *map, SDL_Renderer *renderer, t_player *player, t_map *maze);

#endif  // MAP_H
