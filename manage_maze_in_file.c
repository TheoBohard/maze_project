#include "maze_function.h"
#include "manage_maze_in_file.h"

void save_maze_in_file(char * name, Maze_struct * maze_tab)
{   
    int i = 0;
    int j = 0;

    FILE * maze_file;

    const char* name_file = "cfg_file/maze_score_";
    const char* extension = ".cfg";

    char* file_path;

    file_path = (char*)malloc(100*sizeof(char));

    strcat(file_path, name_file);
    strcat(file_path, name);
    strcat(file_path, extension); 

    printf("Test : %s", file_path);

    maze_file = fopen(file_path,"w+");

    if(maze_file == NULL)
    {
        printf("Erreur d'ouverture du fichier de score");

        exit(1);
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
            if(maze_tab->maze[i*maze_tab->width+j] == 0)
            {
                fprintf(maze_file,"%d", 0);
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

    const char* name_file = "cfg_file/maze_score_";
    const char* extension = ".cfg";

    char* file_path;

    file_path = (char*)malloc(100*sizeof(char));

    strcpy(file_path, name_file);
    strcat(file_path, name);
    strcat(file_path, extension); 

    maze_file = fopen(file_path,"r");

    if(maze_file == NULL)
    {
        printf("Erreur d'ouverture du fichier de score, le fichier n'existe pas");

        choose_action(2);
    }

    fscanf(maze_file, "%d,%d", &width_, &height_);

    printf("W : %d/ H : %d", width_, height_);
    
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
        }
    }

    printf("\n\n");

    fclose(maze_file);

    return maze_tab;
}

