CC=gcc
CFLAGS=-Wall -O -pedantic -ansi
LDFLAGS=
EXEC=maze_prog

all: $(EXEC)

maze_prog: main.o maze_function.o menu.o manage_maze_in_file.o play.o verify_user_entry.o ranking.o
	$(CC) -o maze_prog main.c maze_function.c menu.c manage_maze_in_file.c play.c verify_user_entry.c ranking.c $(LDFLAGS)

clean:
	rm -f *.o core

mrproper: clean
	rm -f $(EXEC)
