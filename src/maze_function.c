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
 * @file maze_function.c
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file permit to manage the maze directly (generate maze/bonus/penalty and display maze)
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "maze_function.h"

Maze_struct * allocate_maze_memory(int height, int width)
{
    Maze_struct * my_maze = (Maze_struct *)malloc(sizeof(Maze_struct));
    my_maze->maze = (int *) malloc(sizeof(int) * width * height);
   
    return my_maze;
}

void generate_maze(Maze_struct * maze_tab)
{
    int i;
    int j;
    int nb = 1;
    int wall_max;
    int counter_break_wall = 0;
    int row = 0;
    int column = 0;
    int cell1;
    int cell2;

    srand(time(NULL));  

    for (i = 0; i < maze_tab->height; i++)
    {
        for (j = 0; j < maze_tab->width; j++)
        {
            /* Even case = 0 to set it as wall and the odd case have to get independent number to make the maze */
            maze_tab->maze[i*maze_tab->width+j] = (i%2 == 1 && j%2 == 1)?(nb++):0;
        }
    }

    wall_max = ((maze_tab->width - 1) * (maze_tab->height -1) /4) -1;

    /* printf("Wall max : %d",wall_max); */

    while(wall_max != counter_break_wall)
    {
        row = (rand() % (maze_tab->height -2)) + 1;


        /* If cell is even we take a odd column */
        if(row%2 == 0)
        {
            column= rand() % ((maze_tab->width-1)/2) * 2 + 1;
            cell1 = maze_tab->maze[(row + 1) * maze_tab->width + column];
            cell2 = maze_tab->maze[(row - 1) * maze_tab->width + column];
        }

            /* If cell is odd we take a even column */
        else
        {
            column = rand() % ((maze_tab->width - 1) /2) * 2;
            cell1 = maze_tab->maze[row * maze_tab->width + (column+1)];
            cell2 = maze_tab->maze[row * maze_tab->width + (column-1)];
        }

        /* We verify if the cells1 and two are not already the same and if the celss is not equals to 0 who is a wall */
        if(cell1 != cell2 && cell1 != 0 && cell2 != 0)
        {
            maze_tab->maze[row*maze_tab->width+column] = cell2;

            for(i = 0; i < maze_tab->height; i++)
            {
                for(j = 0; j < maze_tab->width; j++)
                {
                    if(maze_tab->maze[i*maze_tab->width+j] == cell2)
                    {
                        maze_tab->maze[i*maze_tab->width+j] = cell1;
                    }
                }
            }

            counter_break_wall++;
        }
    }

    maze_tab->maze[maze_tab->width] = 1;
    maze_tab->maze[((maze_tab->width) * (maze_tab->height -1)) -1] = 1;

    maze_tab->position_x = 0;
    maze_tab->position_y = 1;

    generate_bonus(maze_tab,((maze_tab->height+maze_tab->width)/10));
    generate_penalty(maze_tab,((maze_tab->height+maze_tab->width)/10));
}

void display_maze(Maze_struct * maze_tab)
{
    int x;
    int y;

    for (y = 0; y < maze_tab->height; y++)
    {
        for (x = 0; x < maze_tab->width; x++)
        {
            if(x == maze_tab->position_x && y == maze_tab->position_y)
            {
                printf("o");
            }
            else if(maze_tab->maze[y*maze_tab->width+x] > 0)
            {
                printf(" ");
            }
            else if(maze_tab->maze[y*maze_tab->width+x] == -1)
            {
                printf("b");
            }
            else if(maze_tab->maze[y*maze_tab->width+x] == -2)
            {
                printf("m");
            }
            else
            {
                color("47");
                printf(".");
                color("40");
            }
        }

        printf("\n"); 
    }
}

int generate_position(Maze_struct * maze_tab)
{
    int position_index;
    srand(time(NULL));

    position_index = 0;    

    while(maze_tab->maze[position_index] <= 0 ||  position_index == maze_tab->width+1 
        || position_index == ((maze_tab->width) * (maze_tab->height -1)) -1)
    {
        position_index = (rand() % (maze_tab->width*maze_tab->height - 0 + 1));
    }

    return position_index;
}

void generate_bonus(Maze_struct * maze_tab, int number)
{
    int aleatory_number;
    int i;

    for(i = 0; i < number; i++)
    {
        aleatory_number = generate_position(maze_tab);
        maze_tab->maze[aleatory_number] = -1;
    }
}

void generate_penalty(Maze_struct * maze_tab, int number)
{
    int aleatory_number;
    int i;

    for(i = 0; i < number; i++)
    {
        aleatory_number = generate_position(maze_tab);
        maze_tab->maze[aleatory_number] = -2;
    }
}