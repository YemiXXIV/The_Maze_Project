## Author :

Bernie Amponsah <bernieamponsah2@gmail.com>


# The Maze

The Maze is a 3D Maze game that uses ray casting to render a 2D map into a 3D navigable world!


# Usage 
* Execute ./maze or type make run 
* Use up and down arrow keys (keys w and s)
* Use right and left arrow keys  (keys d and a)

# Compilation
```
$ gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o maze `sdl2-config --cflags` `sdl2-config --libs`;
```

