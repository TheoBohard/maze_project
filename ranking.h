/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students. No portion of this
 * document may be reproduced, copied or revised without written
 * permission of the authors.
 */

 /**
 * @file ranking.h
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file contains the declarations to display and manage the rank of each maze
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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