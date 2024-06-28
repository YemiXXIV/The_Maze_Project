#include "maze.h"
#include <stdlib.h>
#include <string.h>

t_map *maze_init(void) {
    t_map *maze = malloc(sizeof(t_map));

    maze->width = MAP_WIDTH;
    maze->height = MAP_HEIGHT;
    maze->data = malloc(MAP_HEIGHT * sizeof(char *));

    for (int i = 0; i < MAP_HEIGHT; i++) {
        maze->data[i] = malloc(MAP_WIDTH * sizeof(char));
    }

    // Initialize map data here

    return maze;
}

void maze_free(t_map *maze) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        free(maze->data[i]);
    }
    free(maze->data);
    free(maze);
}
