#ifndef WALL_H
#define WALL_H

#include <SDL2/SDL_render.h>

typedef struct s_wall {
    SDL_Texture *texture;
    float x;
    float y;
    float width;
    float height;
} t_wall;

void wall_init(t_wall *wall, SDL_Renderer *renderer, float x, float y, float width, float height);
void wall_draw(t_wall *wall, SDL_Renderer *renderer);

#endif /* WALL_H */
