#include "player.h"
#include "SDL.h"

t_player *player_init(int x, int y, SDL_Texture *texture) {
    t_player *player = malloc(sizeof(t_player));
    player->x = x;
    player->y = y;
    player->texture = texture;
    return player;
}

void player_free(t_player *player) {
    free(player);
}
