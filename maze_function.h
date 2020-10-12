#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Maze_struct
{
    int position_x;
    int position_y;
    int width;
    int height;
    int * maze;
    char * name;
} Maze_struct;

void generate_maze(Maze_struct * maze_tab);
void display_maze(Maze_struct * maze_tab);
Maze_struct * allocate_maze_memory(int height, int width);