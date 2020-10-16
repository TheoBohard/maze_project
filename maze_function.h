#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define color(param) printf("\033[%sm",param)

typedef struct Maze_struct
{
    int position_x;
    int position_y;
    int width;
    int height;
    int score;
    int * maze;
    char * name;
} Maze_struct;

void generate_maze(Maze_struct * maze_tab);
void display_maze(Maze_struct * maze_tab);
Maze_struct * allocate_maze_memory(int height, int width);
int generate_position(Maze_struct * maze_tab);
void generate_bonus(Maze_struct * maze_tab, int number);
void generate_penalty(Maze_struct * maze_tab, int number);