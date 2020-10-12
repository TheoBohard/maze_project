#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_maze_in_file(char * name, Maze_struct * maze_tab);
Maze_struct * load_maze_from_file(char * name);