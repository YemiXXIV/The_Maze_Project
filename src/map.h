#ifndef MAP_H
#define MAP_H

typedef enum {
    MAP_SPACE,
    MAP_WALL
} t_map_data;

typedef struct {
    int width;
    int height;
    t_map_data **data;
    SDL_Texture *floor;
    SDL_Texture *ceiling;
    SDL_Texture *walls;
} t_map;

t_map *map_init(SDL_Renderer *renderer, int width, int height);
void map_free(t_map *map);
void map_set_wall(t_map *map, int x, int y);
void map_unset_wall(t_map *map, int x, int y);
int map_is_wall(t_map *map, int x, int y);
void map_draw(t_map *map, SDL_Renderer *renderer, t_player *player);

#endif  // MAP_H
