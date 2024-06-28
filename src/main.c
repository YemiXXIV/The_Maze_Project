#include <SDL2/SDL.h>
#include "map.h"
#include "raycasting.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Renderer *renderer = SDL_CreateRenderer(NULL, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    int running = 1;

    t_player player;
    t_map_data map_data;
    map_init(&map_data, renderer);
    t_map *maze = &map_data.map;
    raycasting_init(&player, maze);

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_RenderClear(renderer);
        raycasting_draw_walls(renderer, &player, maze);
        map_draw(map_data.map, renderer, &player, maze);
        SDL_RenderPresent(renderer);
    }

    map_free(maze);
    SDL_Quit();
    return 0;
}
