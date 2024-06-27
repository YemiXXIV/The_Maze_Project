#include <math.h>
#include "raycasting.h"
#include "maze.h"

// Function to calculate the distance to the wall
float distance_to_wall(Maze *maze, float x, float y, float angle) {
    float distance = 0;
    float step_x = cos(angle);
    float step_y = sin(angle);

    while (1) {
        x += step_x;
        y += step_y;
        distance += 1;

        if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
            break;
        }

        if (maze->grid[(int)y][(int)x] == WALL) {
            break;
        }
    }

    return distance;
}

// Function to cast a ray
void cast_ray(Maze *maze, float x, float y, float angle, float *distance, float *wall_hit_x, float *wall_hit_y) {
    *distance = distance_to_wall(maze, x, y, angle);
    float step_x = cos(angle);
    float step_y = sin(angle);

    x += step_x * *distance;
    y += step_y * *distance;

    *wall_hit_x = x;
    *wall_hit_y = y;
}

// Function to render the 3D scene
void render_scene(Maze *maze, float player_x, float player_y, float player_angle) {
    int screen_width = 640;
    int screen_height = 480;
    float fov = 60 * M_PI / 180;
    float half_fov = fov / 2;

    for (int x = 0; x < screen_width; x++) {
        float angle = player_angle - half_fov + (x / (float)screen_width) * fov;
        float distance;
        float wall_hit_x;
        float wall_hit_y;

        cast_ray(maze, player_x, player_y, angle, &distance, &wall_hit_x, &wall_hit_y);

        int wall_height = (int)(screen_height / distance);
        int top = (screen_height - wall_height) / 2;
        int bottom = top + wall_height;

        for (int y = top; y < bottom; y++) {
            printf(" ");
        }

        for (int y = bottom; y < screen_height; y++) {
            printf("-");
        }

        printf("\n");
    }
}
