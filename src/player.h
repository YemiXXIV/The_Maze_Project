#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int x;
    int y;
    SDL_Texture *texture;  // Add this line
} t_player;

t_player *player_init(int x, int y, SDL_Texture *texture);
void player_free(t_player *player);

#endif  // PLAYER_H
