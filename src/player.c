#include "player.h"

t_player *player_init(int x, int y, SDL_Texture *texture) {
    t_player *player = malloc(sizeof(t_player));
    player->x = x;
    player->y = y;
    player->texture = texture;
    player->angle = 0.0f;
    return player;
}
