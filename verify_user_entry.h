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
 * @file verify_user_entry.h
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file contains the declarations to verify the user entry
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
 * @brief This function permit to ask for a int to the user
 * 
 * @return int The value choosed by the user
 */

int ask_int_to_user();

/**
 * @brief This function permit to verify if the value is an odd value
 * 
 * @param var The value we want to check
 * @return int A odd value variable
 */

int verify_odd_value(int var);

/**
 * @brief This function permit to clear the buffer
 * 
 */

void clear_buffer();

/**
 * @brief This function permit to remove a specific char from a string
 * 
 * @param string The string on which we want to remove a char
 * @param character The char we want to remove
 */
 
void remove_char_from_string(char * string, int character);