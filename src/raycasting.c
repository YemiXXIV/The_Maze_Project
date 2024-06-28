#include "raycasting.h"
#include "maze.h"
#include <SDL2/SDL.h>

void raycasting_init(t_player *player, t_map *maze) {
    player->x = 10.0f;
    player->y = 10.0f;
    player->angle = 0.0f;
}

void raycasting_draw_walls(SDL_Renderer *renderer, t_player *player, t_map *maze) {
    // Raycasting algorithm implementation here
    // Draw walls on the renderer
}
