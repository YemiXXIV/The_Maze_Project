#ifndef MAZE_H
#define MAZE_H

#define MAZE_WIDTH 21
#define MAZE_HEIGHT 11

typedef struct {
    int width;
    int height;
    char **cells;
} Maze;

Maze *maze_create(void);
void maze_destroy(Maze *maze);
void maze_generate(Maze *maze);
int maze_is_wall(Maze *maze, int x, int y);

#endif  // MAZE_H
