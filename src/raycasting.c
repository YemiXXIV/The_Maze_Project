#include "raycasting.h"
#include "map.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <math.h>

void raycasting_init(t_player *player) {
    player->angle = 0.0f;
}

void raycasting_draw_walls(SDL_Renderer *renderer, t_player *player, t_map *maze) {
    // Your implementation here
}
