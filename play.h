#include <stdio.h>
#include <stdlib.h>

void play(Maze_struct * maze_tab);
int move_is_possible(Maze_struct * maze_tab, char move);
void move_pos(Maze_struct * maze_tab, char move);
void game_is_finish(Maze_struct * maze_tab);