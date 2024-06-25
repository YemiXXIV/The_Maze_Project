// maze.c

#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Maze *maze_load(const char *filename) {
    Maze *maze = malloc(sizeof(Maze));
    if (!maze) return NULL;

    FILE *file = fopen(filename, "r");
    if (!file) {
        free(maze);
        return NULL;
    }

    fscanf(file, "%d %d", &maze->width, &maze->height);

    maze->cells = malloc(maze->height * sizeof(char *));
    for (int i = 0; i < maze->height; i++) {
        maze->cells[i] = malloc(maze->width * sizeof(char));
    }

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            fscanf(file, " %c", &maze->cells[i][j]);
        }
    }

    fclose(file);
    return maze;
}

void maze_free(Maze *maze) {
    if (!maze) return;

    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

char maze_get_cell(Maze *maze, int x, int y) {
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
        return '#'; // out of bounds, return wall
    }
    return maze->cells[y][x];
}

void maze_set_cell(Maze *maze, int x, int y, char value) {
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
        return; // out of bounds, do nothing
    }
    maze->cells[y][x] = value;
}
