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

/**
 * @brief Struct to define the ranking of a maze
 * 
 */

typedef struct Ranking_Struct
{
    char * name;
    int score;
} Ranking_Struct;

/**
 * @brief This function permit to display the rank of a maze
 * 
 * @param name The name of the maze
 */

void display_rank(char * name);

/**
 * @brief This function permit to add a score of the player on a maze on his rankfile
 * 
 * @param name The name of the maze 
 * @param name_player The name of the player
 * @param score The score of the player
 */

void add_rank(char * name, char * name_player, int score);

/**
 * @brief This function permit to count the number of line of a file
 * 
 * @param file_path The path of the file
 * @return int The number of line
 */

int count_line(char * file_path);

/**
 * @brief This function permit to create an empty file of ranking
 * 
 * @param file_path The path where we want to create the file
 */

void create_empty_file(char * file_path);

/**
 * @brief This function permit to check if a file exist
 * 
 * @param file_path The path of the ifle
 * @return int Return 1 if the file exist, 0 if the file don't exist
 */

int check_file_exist(char * file_path);