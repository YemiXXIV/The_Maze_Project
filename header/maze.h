// maze.h

#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maze structure
typedef struct {
    int width;
    int height;
    char **cells;
} Maze;

// Function to load a maze from a file
Maze *maze_load(const char *filename);

// Function to free a maze
void maze_free(Maze *maze);

// Function to get a cell value in the maze
char maze_get_cell(Maze *maze, int x, int y);

// Function to set a cell value in the maze
void maze_set_cell(Maze *maze, int x, int y, char value);

#endif // MAZE_H
