#ifndef GAME_H
#define GAME_H

typedef struct {
    Maze *maze;
    Ray *ray;
    float player_x;
    float player_y;
    float player_direction;
} Game;

Game *game_create(void);
void game_destroy(Game *game);
void game_update(Game *game);
void game_render(Game *game);

#endif  // GAME_H
