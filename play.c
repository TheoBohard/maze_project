#include "maze_function.h"
#include "play.h"
#include "menu.h"
#include "ranking.h"
#include "verify_user_entry.h"

void play(Maze_struct * maze_tab)
{
    char move;
    int maze_finished = 0;

    if(maze_tab->maze[0] != 0)
        display_menu();

    while(maze_finished == 0)
    {
        while (getchar() != '\n');

        move = getchar();

        if(move_is_possible(maze_tab, putchar(move)) == 1)
        {
            move_pos(maze_tab,putchar(move));
            printf("\n");
            display_maze(maze_tab);
        }
        else
        {
            printf("\nThis move is not possible !\n");
            display_maze(maze_tab);
        }
    }
}

int move_is_possible(Maze_struct * maze_tab, char move)
{   
    if(move == 'z' || move == 'Z')
    {
        if(maze_tab->maze[(maze_tab->position_y - 1)*maze_tab->width+maze_tab->position_x] != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(move == 'q' || move == 'Q')
    {
        if(maze_tab->maze[maze_tab->position_y*maze_tab->width+(maze_tab->position_x - 1)] != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(move == 's' || move == 'S')
    {
        if(maze_tab->maze[(maze_tab->position_y + 1)*maze_tab->width+maze_tab->position_x] != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(move == 'd' || move == 'D')
    {
        if(maze_tab->maze[maze_tab->position_y*maze_tab->width+(maze_tab->position_x + 1)] != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    return 0;
}

void move_pos(Maze_struct * maze_tab, char move)
{
    if(move == 'z' || move == 'Z')
    {
        maze_tab->position_y -= 1;
    }

    if(move == 'q' || move == 'Q')
    {
        maze_tab->position_x -= 1;
    }

    if(move == 's' || move == 'S')
    {
        maze_tab->position_y += 1;
    }

    if(move == 'd' || move == 'D')
    {
        maze_tab->position_x += 1;
    }

    maze_tab->score++;

    if(maze_tab->maze[maze_tab->position_y*maze_tab->width+maze_tab->position_x] == -1)
    {
        /*maze_tab->score -= rand() % 5 + 1;*/
        maze_tab->score -= 3;
        maze_tab->maze[maze_tab->position_y*maze_tab->width+maze_tab->position_x] = 1;
    }

    if(maze_tab->maze[maze_tab->position_y*maze_tab->width+maze_tab->position_x] == -2)
    {
        /*maze_tab->score += rand() % 5 + 1;*/
        maze_tab->score += 3;
        maze_tab->maze[maze_tab->position_y*maze_tab->width+maze_tab->position_x] = 1;
    }

    printf("\n\nScore : %d\n", maze_tab->score);

    game_is_finish(maze_tab);
}

void game_is_finish(Maze_struct * maze_tab)
{
    if(maze_tab->position_x == maze_tab->width - 1 && 
       maze_tab->position_y == maze_tab->height - 2)
    {
        char player_name[50];
        printf("The game is finished, you will go back to the menu\n");
        maze_tab->position_x = 0;
        maze_tab->position_y = 1;
        /*Function display score into save score*/
        printf("Votre score est le suivant : %d\n", maze_tab->score);

        printf("What is your name to save your score ?\n");
        scanf("%s", player_name);
        remove_char_from_string(player_name,'/');
        remove_char_from_string(player_name,'\\');
        
        add_rank(maze_tab->name, player_name, maze_tab->score);
        display_rank(maze_tab->name);

        maze_tab->score = 0;

        free_struct();
        display_menu();
    }
}