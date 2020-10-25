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
 * @file manage_maze_in_file.h
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file contains the declarations to manage maze on file (save and load)
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief This function permit to save a maze on a file
 * 
 * @param maze_tab This is maze struct to save
 */

void save_maze_in_file(Maze_struct * maze_tab);

/**
 * @brief This function permit to load a maze from a file
 * 
 * @param name This is the name of the file to open
 * @return Maze_struct* This is the Maze_struct struct to return
 */
 
Maze_struct * load_maze_from_file(char * name);