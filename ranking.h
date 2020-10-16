#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Ranking_Struct
{
    char * name;
    int score;
} Ranking_Struct;

void display_rank(char * name);
void add_rank(char * name, char * name_player, int score);
int count_line(char * file_path);
void create_empty_file(char * file_path);
int check_file_exist(char * file_path);