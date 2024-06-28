#include "player.h"

void player_init(t_player *player, int x, int y, int direction) {
    player->x = x;
    player->y = y;
    player->direction = direction;
}

void player_move(t_player *player, t_map *map, int dx, int dy) {
    int new_x = player->x + dx;
    int new_y = player->y + dy;
    if (new_x >= 0 && new_x < map->width && new_y >= 0 && new_y < map->height) {
        player->x = new_x;
        player->y = new_y;
    }
}
