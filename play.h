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
 * @file play.h
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file contains the declarations to play on a maze
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function permit to play on a maze
 * 
 * @param maze_tab The maze we want to play
 */

void play(Maze_struct * maze_tab);

/**
 * @brief This function permit to verify if a move is possible
 * 
 * @param maze_tab The maze in which we want to check a move
 * @param move The direction of the move
 * @return int Return 0 if we can, 1 if we can't
 */

int move_is_possible(Maze_struct * maze_tab, char move);

/**
 * @brief This function permit to move the player on a maze
 * 
 * @param maze_tab The maze in which we want to move
 * @param move The direction of the move
 */

void move_pos(Maze_struct * maze_tab, char move);

/**
 * @brief This function permit to check if the game is finished
 * 
 * @param maze_tab The maze on which we want to check if we are on the end
 */

void game_is_finish(Maze_struct * maze_tab);