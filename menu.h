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
 * @file menu.h
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file contains the declarations to display the menu and choose one of the action
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include "manage_maze_in_file.h"

/**
 * @brief This function permit to display the menu to manage/play on maze
 * 
 */

void display_menu();

/**
 * @brief This function permit to choose one of the action displayed on the menu
 * 
 * @param action The hint of the action we want to choose
 */

void choose_action(int action);

/**
 * @brief This function permit to display the .cfg file on a directory
 * 
 * @param path The path of the folder we want to display
 */

void list_directory(char * path);

/**
 * @brief This function permit to free a Maze_struct struct
 * 
 */

void free_struct();

Maze_struct * my_maze_loaded;
