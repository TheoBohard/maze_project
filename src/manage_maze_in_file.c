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
 * @file manage_maze_in_file.c
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file permit to manage maze on file (save and load)
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "maze_function.h"
#include "manage_maze_in_file.h"
#include "menu.h"

void save_maze_in_file(Maze_struct * maze_tab)
{   
    int i = 0;
    int j = 0;

    FILE * maze_file;

    const char* name_file = "./files/saves_files/maze_";
    const char* extension = ".cfg";

    char* file_path;

    file_path = (char*)malloc(100*sizeof(char));

    strcat(file_path, name_file);
    strcat(file_path, maze_tab->name);
    strcat(file_path, extension); 

    maze_file = fopen(file_path,"w+");

    if(maze_file == NULL)
    {
        printf("We can't open the maze file please retry the action!");

        display_menu();
    }

    fprintf(maze_file,"%d,%d\n",maze_tab->width, maze_tab->height);
    
    for (i = 0; i < maze_tab->height; i++)
    {
        for (j = 0; j < maze_tab->width; j++)
        {
            if(maze_tab->maze[i*maze_tab->width+j] > 0)
            {
                fprintf(maze_file,"%d", 1);
            }
            else if(maze_tab->maze[i*maze_tab->width+j] == 0)
            {
                fprintf(maze_file,"%d", 0);
            }
            else if(maze_tab->maze[i*maze_tab->width+j] == -1)
            {
                fprintf(maze_file,"%d", 2);
            }            
            else if(maze_tab->maze[i*maze_tab->width+j] == -2)
            {
                fprintf(maze_file,"%d", 3);
            }
            
        }      

        fprintf(maze_file,"\n");
    }



    fclose(maze_file);
}

Maze_struct * load_maze_from_file(char * name)
{
    int i;
    int j;
    int width_;
    int height_;

    Maze_struct * maze_tab;

    FILE * maze_file;

    const char* name_file = "./files/saves_files/maze_";
    const char* extension = ".cfg";

    char* file_path;

    file_path = (char*)malloc(100*sizeof(char));

    strcpy(file_path, name_file);
    strcat(file_path, name);
    strcat(file_path, extension); 

    maze_file = fopen(file_path,"r");

    if(maze_file == NULL)
    {
        printf("The maze you want to open don't exist");

        choose_action(2);
    }

    fscanf(maze_file, "%d,%d", &width_, &height_);
    
    maze_tab = allocate_maze_memory(width_, height_);

    maze_tab->width = width_;
    maze_tab->height = height_;
    maze_tab->name = name;
    maze_tab->position_x = 0;
    maze_tab->position_y = 1;


    for (i = 0; i < maze_tab->height; i++)
    {
        for (j = 0; j < maze_tab->width; j++)
        {
            fscanf(maze_file, "%1d", &maze_tab->maze[i*maze_tab->width+j]);

            if(maze_tab->maze[i*maze_tab->width+j] == 2)
            {
               maze_tab->maze[i*maze_tab->width+j] = -1; 
            }
            
            if(maze_tab->maze[i*maze_tab->width+j] == 3)
            {
               maze_tab->maze[i*maze_tab->width+j] = -2; 
            }
        }
    }

    printf("\n\n");

    fclose(maze_file);

    return maze_tab;
}

