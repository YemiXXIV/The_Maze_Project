#ifndef RAYCASTING_H
#define RAYCASTING_H

#define RAYCASTING_FOV 60.0f
#define RAYCASTING_RANGE 10.0f

typedef struct {
    float x;
    float y;
    float direction;
} Ray;

void raycasting_cast(Ray *ray, Maze *maze);
float raycasting_get_distance(Ray *ray);

#endif  // RAYCASTING_H
