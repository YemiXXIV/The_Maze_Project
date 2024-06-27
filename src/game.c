#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

// Function to handle player movement
void move_player(Maze *maze, int *x, int *y, char direction) {
    switch (direction) {
        case 'N':
            if (*y > 0 && maze->grid[*y - 1][*x]!= WALL) {
                (*y)--;
            }
            break;
        case 'S':
            if (*y < maze->height - 1 && maze->grid[*y + 1][*x]!= WALL) {
                (*y)++;
            }
            break;
        case 'E':
            if (*x < maze->width - 1 && maze->grid[*y][*x + 1]!= WALL) {
                (*x)++;
            }
            break;
        case 'W':
            if (*x > 0 && maze->grid[*y][*x - 1]!= WALL) {
                (*x)--;
            }
            break;
        default:
            printf("Invalid direction. Try again!\n");
            break;
    }
}

// Function to check if the player has reached the goal
int has_reached_goal(Maze *maze, int x, int y) {
    return maze->grid[y][x] == GOAL;
}

// Function to print the game status
void print_game_status(Maze *maze, int x, int y) {
    printf("Player position: (%d, %d)\n", x, y);
    printf("Maze:\n");
    print_maze(maze);
}

// Function to play the game
void play_game(Maze *maze) {
    int player_x = 0;
    int player_y = 0;

    while (1) {
        print_game_status(maze, player_x, player_y);

        char input;
        printf("Enter a direction (N/S/E/W): ");
        scanf(" %c", &input);

        move_player(maze, &player_x, &player_y, input);

        if (has_reached_goal(maze, player_x, player_y)) {
            printf("Congratulations! You've reached the goal!\n");
            break;
        }
    }
}
