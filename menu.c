#include "maze_function.h"
#include "menu.h"

Maze_struct * my_maze_loaded;

void display_menu()
{
    int action_choosed;

    printf("Hello :)\n");
    printf("Welcome on this game :)\n");
    printf("1. Create a new maze\n");
    printf("2. Load a maze\n");
    printf("3. Play\n");
    printf("4. Exit\n");

    scanf("%d",&action_choosed);

    choose_action(action_choosed);
}

void choose_action(int action)
{
    char name[50];

    int width_;
    int height_;

    struct dirent * reading;
    DIR * dir;

    Maze_struct * my_maze;

    switch(action)
    {
        case 1:
            
            printf("Please indicate the height of your maze which have to be odd ?\n");
            scanf("%d",&width_);
            printf("Please indicate the width of your maze which have to be odd ?\n");
            scanf("%d",&height_);
            printf("What is the name of the maze ?\n");
            scanf("%s", &name);


            if(height_%2 == 0 || width_ %2 == 0)
            {
                printf("\nPlease enter a correct value (ODD and DIGIT value)\n");
                choose_action(1);
            }

            my_maze = allocate_maze_memory(width_, height_);
            my_maze->name = name;
            my_maze->width = width_;
            my_maze->height = height_;

            printf("Name = %s \n", my_maze->name);

            generate_maze(my_maze);
            display_maze(my_maze);

            save_maze_in_file(name, my_maze);
            /* TODO : return the struct */

            display_menu();

            break;
        
        case 2 :

            dir = opendir("./cfg_file/" );
            while ((reading = readdir(dir))) 
            {
                printf("%s\n", reading->d_name);
            }
            closedir(dir);

            printf("\nYou can chose one of the game by writing the name between score_ and .cfg\n");

            while (getchar() != '\n');

            scanf("%s", &name);

            my_maze_loaded = load_maze_from_file(name);

            display_maze(my_maze_loaded);

            printf("\n");

            display_menu();
        
            break;
            
        case 3:
            play(my_maze_loaded);
            break;
        default:
            display_menu();
            break;

    }
}