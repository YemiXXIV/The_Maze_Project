#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

typedef struct {
    int x;
    int y;
    SDL_Texture *texture;
    float angle;  // Add this line
} t_player;

t_player *player_init(int x, int y, SDL_Texture *texture);
void player_free(t_player *player);

#endif  // PLAYER_H
