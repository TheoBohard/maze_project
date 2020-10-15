#include "maze_function.h"
#include "menu.h"
#include "play.h"
#include "verify_user_entry.h"
#include "ranking.h"

void display_menu()
{
    int action_choosed = 0;

    printf("Hello :)\n");
    printf("Welcome on this game :)\n");
    printf("1. Create a new maze\n");
    printf("2. Load a maze\n");
    printf("3. Play\n");
    printf("4. Exit\n");

    action_choosed = ask_int_to_user(action_choosed);

    choose_action(action_choosed);
}

void choose_action(int action)
{
    char name[50];
    char scorename[] = "premier";
    char name_player[] = "JeSuisUnPersonnageTresFort";

    int width_ = 0;
    int height_ = 0;

    Maze_struct * my_maze;

    switch(action)
    {
        case 1:
            
            printf("Please indicate the width of your maze which have to be odd ?\n");
            width_ = ask_int_to_user(width_);
            width_ = verify_odd_value(width_);

            printf("Please indicate the height of your maze which have to be odd ?\n");
            height_ = ask_int_to_user(height_);
            height_ = verify_odd_value(height_);

            printf("What is the name of the maze ?\n");
            scanf("%s", name);
            remove_char_from_string(name,'/');
            remove_char_from_string(name,'\\');

            my_maze = allocate_maze_memory(width_, height_);
            my_maze->name = name;
            my_maze->width = width_;
            my_maze->height = height_;

            generate_maze(my_maze);
            display_maze(my_maze);

            save_maze_in_file(name, my_maze);
            free(my_maze);
            my_maze = NULL;

            /* TODO : return the struct */

            display_menu();

            break;
        
        case 2 :

            list_directory("./cfg_file/");

            printf("\nYou can chose one of the game by writing the name between score_ and .cfg\n");

            clear_buffer();

            scanf("%s", name);

            my_maze_loaded = load_maze_from_file(name);

            display_maze(my_maze_loaded);

            printf("\n");

            display_menu();
        
            break;
            
        case 3:

            if(my_maze_loaded == NULL)
            {
                printf("You have to load a maze ! \n");
                display_menu();
            }
            else
            {
                display_maze(my_maze_loaded);
                play(my_maze_loaded);
            }
            
            break;

        case 4:
            exit(1);
            break;

        case 5:
            add_rank(scorename,name_player,-18);
            display_rank(scorename);
            break;

        default:
            printf("Please enter a good value to choose your option on the menu \n");
            display_menu();
            break;

    }
}

void list_directory(char * path)
{
        struct dirent * reading;
        DIR * directory;

        directory = opendir(path);

        printf("\n");

        if(directory == NULL)
        {
            printf("The path you specified doesn't exist, please create cfg_file folder on the program folder\n");
        }
        
        while ((reading = readdir (directory)) != NULL)
        {

            if(strstr(reading->d_name , ".cfg" ))
            {
                printf("%s\n", reading->d_name);
            }
        }
            
        closedir(directory);
}


void free_struct()
{
    free(my_maze_loaded->maze);
    free(my_maze_loaded);
    my_maze_loaded = NULL;
}