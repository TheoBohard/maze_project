#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include "manage_maze_in_file.h"

void display_menu();
void choose_action(int action);
Maze_struct * my_maze_loaded;
void list_directory(char * path);
void free_struct();
