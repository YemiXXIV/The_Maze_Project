#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "map.h"
#include "raycasting.h"
#include "player.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Renderer *renderer = SDL_CreateRenderer(NULL, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture *player_texture = IMG_LoadTexture(renderer, "player.bmp");

    t_map *maze = map_init(renderer, 20, 20); // Initialize map with 20x20 size
    t_player *player = player_init(10, 10, player_texture);
    raycasting_init(player); // Initialize raycasting

    //... rest of the code...
    return 0;
}
