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
 * @file ranking.c
 * @author Théo BOHARD (theo.bohard@ecole.ensicaen.fr)
 * @brief This file permit to display and manage the rank of each maze
 * @version 1.0
 * @date 2020-10-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "ranking.h"
#include "verify_user_entry.h"

void create_empty_file(char * file_path)
{
    FILE * file;

    file = fopen(file_path, "w");
    
    fclose(file);
}

int check_file_exist(char * file_path)
{
    FILE * file;
    
    file = fopen(file_path, "r");
    
    if(file)
    {
        fclose(file);
        return 1;
    }
    else
    {
        return 0;
    }
}

int count_line(char * file_path)
{
    int ch;
    int lines = 0;

    FILE * file;


    if(!check_file_exist(file_path))
    {
        create_empty_file(file_path);
    }

    file = fopen(file_path, "r");
    
    lines++;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
            lines++;
    }

    fclose(file);
    
    return lines;
}

void display_rank(char * name)
{
    FILE * score_file;

    char player_name[50];
    int score_player;
    int i;
    int lines = 0;

    const char* name_file = "score_file/maze_";
    const char* extension = ".score";

    char* file_path;

    file_path = (char*)malloc(100*sizeof(char));

    strcpy(file_path, name_file);
    strcat(file_path, name);
    strcat(file_path, extension); 
    
    lines = count_line(file_path);

    score_file = fopen(file_path,"r");

    if(score_file == NULL)
    {
        printf("The score file you want to open don't exist");
    }

    for(i = 0; i < lines-1; i++)
    {
            fscanf(score_file, "%d,%s", &score_player, player_name);
            printf("Rank #%d : %s, Score = %d \n", i+1, player_name, score_player);
    }

    fclose(score_file);
}

void add_rank(char * name, char * name_player, int score)
{
    int i;
    int x;
    int y;
    int lines = 0;

    Ranking_Struct * rank[11];
    Ranking_Struct * temp = malloc(sizeof(Ranking_Struct));

    char player_name[50];
    int score_player;

    FILE * score_file;

    const char* name_file = "score_file/maze_";
    const char* extension = ".score";

    char* file_path;

    file_path = (char*)malloc(100*sizeof(char));

    strcpy(file_path, name_file);
    strcat(file_path, name);
    strcat(file_path, extension); 

    lines = count_line(file_path);

    for(i = 0; i < lines+1; i++)
    {
        rank[i] = malloc(sizeof(Ranking_Struct));
        rank[i]->name = malloc(sizeof(char) * 50);
    }

    score_file = fopen(file_path,"r");

    if(score_file == NULL)
    {
        printf("The score file you want to open don't exist");;
    }

    for(i = 0; i < lines-1; i++)
    {
            fscanf(score_file, "%d,%s", &score_player, player_name);
            if(strcmp(player_name, ""))
            {
                rank[i]->score = score_player;
                rank[i]->name = malloc(sizeof(char)*strlen(player_name));
                printf("Le joueur %s à un score de %d\n", rank[i]->name, rank[i]->score);
                strcpy(rank[i]->name, player_name);
            }
    }

    fclose(score_file);

    rank[lines-1]->score = score;
    rank[lines-1]->name = name_player;

    if(lines > 1)
    {
        for(x=0;x<lines;x++)
            for(y=x+1;y<lines;y++)
                if(rank[x]->score > rank[y]->score)
                {
                    temp = rank[x];
                    rank[x] = rank[y];
                    rank[y] = temp;
                }

    }


    score_file = fopen(file_path,"w+");
    
    if(lines > 10)
    {
        lines = 10;
    }

    for(i = 0; i < lines; i++)
    {
        fprintf(score_file,"%d,%s\n", rank[i]->score, rank[i]->name);
    } 

    fclose(score_file);
    
}