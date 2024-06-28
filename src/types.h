#ifndef TYPES_H
#define TYPES_H

typedef struct {
    int x, y;
} t_point;

typedef struct {
    int width, height;
    t_point **grid;
} t_map;

typedef struct {
    int x, y;
    int direction;
} t_player;

#endif  // TYPES_H
