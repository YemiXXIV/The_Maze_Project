CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
LDFLAGS=-lSDL2

maze_game: src/main.c src/maze.c src/raycasting.c
    $(CC) $(CFLAGS) -o maze_game src/main.c src/maze.c src/raycasting.c $(LDFLAGS)

clean:
    rm -f maze_game
