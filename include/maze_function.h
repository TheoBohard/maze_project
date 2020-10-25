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
 * @file maze_function.h
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file contains the declarations to manage the maze directly (generate maze/bonus/penalty and display maze)
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define color(param) printf("\033[%sm",param)

/**
 * @brief Struct to define a maze
 * 
 */
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

/**
 * @brief This function permit to generate a maze and generate the bonus and penalty with the next functions
 * 
 * @param maze_tab Maze_struct struct to store the maze
 */

void generate_maze(Maze_struct * maze_tab);

/**
 * @brief This function permit to display a maze
 * 
 * @param maze_tab Maze_struct to display the maze
 */

void display_maze(Maze_struct * maze_tab);

/**
 * @brief This function permit to allocate the dynamic memory of a maze struct
 * 
 * @param height Height of the maze to allocate memory 
 * @param width Width of the maze to allocate memory
 * @return Maze_struct* 
 */

Maze_struct * allocate_maze_memory(int height, int width);

/**
 * @brief This function permit to generate aleatory position to after generate bonus and penalty
 * 
 * @param maze_tab 
 * @return int A hint of position to generate bonus or penalty after
 */

int generate_position(Maze_struct * maze_tab);

/**
 * @brief This function permit to generate number bonus on the maze 
 * 
 * @param maze_tab The maze where we want to generate bonus
 * @param number The number of bonus we want to generate
 */

void generate_bonus(Maze_struct * maze_tab, int number);

/**
 * @brief This function permit to generate number penalty on the maze
 * 
 * @param maze_tab The maze where we want to generate penalty
 * @param number The number of penalty we want to generate
 */

void generate_penalty(Maze_struct * maze_tab, int number);

