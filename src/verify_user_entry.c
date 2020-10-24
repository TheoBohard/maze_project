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
 * @file verify_user_entry.c
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file permit to verify the user entry
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "verify_user_entry.h"

int ask_int_to_user()
{
    int var;

    while(scanf("%d", &var) != 1)
    {
        printf("The value that you have enter is incorrect ! \n");
        clear_buffer();
    }

    return var;
}

int verify_odd_value(int var)
{
    if(var %2 == 1)
    {
        return var;
    }
    else
    {
        printf("The value is not an odd value ! \nPlease re-enter a odd value ! \n");
        var = ask_int_to_user();
        var = verify_odd_value(var);
    }

    return var;
}

void clear_buffer()
{
    while (getchar() != '\n');
}

void remove_char_from_string(char * string, int character)
{ 
    int i;
    int j = strlen(string);
    int n = strlen(string);

    for(i=j=0; i<n; i++) 
    {
        if (string[i] != character) 
        {
            string[j++] = string[i]; 
        }
    }

    string[j] = '\0'; 
} 