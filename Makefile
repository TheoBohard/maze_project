CC=gcc
CFLAGS=-Wall -O -pedantic -ansi
OBJS= main.o maze_function.o menu.o manage_maze_in_file.o play.o verify_user_entry.o ranking.o
LDFLAGS=
EXEC=maze_prog

all: $(EXEC)

${EXEC}: ${OBJS}
	mkdir -p cfg_file
	mkdir -p score_file
	$(CC) $^ -o $@ ${LDFLAGS}

main.o: main.c
	$(CC) $(CFLAGS) $< -c

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) $< -c

manage_maze_in_file.o: manage_maze_in_file.c manage_maze_in_file.h
	$(CC) $(CFLAGS) $< -c

play.o: play.c play.h
	$(CC) $(CFLAGS) $< -c

verify_user_entry.o: verify_user_entry.c verify_user_entry.h
	$(CC) $(CFLAGS) $< -c

ranking.o: ranking.c ranking.h
	$(CC) $(CFLAGS) $< -c

maze_function.o: maze_function.c maze_function.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm -f *.o core
