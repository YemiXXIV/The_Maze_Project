#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int main() {
    // Initialize the game
    printf("Welcome to the Maze Game!\n");

    // Create a new maze
    Maze *maze = create_maze("maps/map1.txt");

    if (maze == NULL) {
        printf("Error: Unable to create maze.\n");
        return 1;
    }

    // Print the maze
    printf("Maze:\n");
    print_maze(maze);

    // Play the game
    int player_x = 0;
    int player_y = 0;
    while (1) {
        // Get user input
        char input;
        printf("Enter a direction (N/S/E/W): ");
        scanf(" %c", &input);

        // Move the player
        switch (input) {
            case 'N':
                player_y--;
                break;
            case 'S':
                player_y++;
                break;
            case 'E':
                player_x++;
                break;
            case 'W':
                player_x--;
                break;
            default:
                printf("Invalid input. Try again!\n");
                continue;
        }

        // Check if the player is still in the maze
        if (player_x < 0 || player_x >= maze->width || player_y < 0 || player_y >= maze->height) {
            printf("You've reached the edge of the maze! Game over.\n");
            break;
        }

        // Check if the player has reached the goal
        if (maze->grid[player_y][player_x] == GOAL) {
            printf("Congratulations! You've reached the goal!\n");
            break;
        }

        // Print the updated maze
        printf("Maze:\n");
        print_maze(maze);
    }

    // Clean up
    free_maze(maze);

    return 0;
}
