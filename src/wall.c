#include "wall.h"
#include <SDL2/SDL_image.h>

void wall_init(t_wall *wall, SDL_Renderer *renderer, float x, float y, float width, float height) {
    SDL_Surface *surface = IMG_Load("wall.bmp");
    wall->texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    wall->x = x;
    wall->y = y;
    wall->width = width;
    wall->height = height;
}

void wall_draw(t_wall *wall, SDL_Renderer *renderer) {
    SDL_Rect wall_rect = {wall->x, wall->y, wall->width, wall->height};
    SDL_RenderCopy(renderer, wall->texture, NULL, &wall_rect);
}
