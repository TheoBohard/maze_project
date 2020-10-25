.PHONY: maze_prog test clean doc help

CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ansi
CPPFLAGS = -I ./include/
SRC_DIR = ./src
OBJ_DIR = ./obj
TEST_DIR = ./tests
OBJS= $(addprefix $(OBJ_DIR)/, main.o maze_function.o menu.o manage_maze_in_file.o play.o verify_user_entry.o ranking.o)
OBJS_TEST = $(addprefix $(OBJ_DIR)/, test_maze.o maze_function.o menu.o manage_maze_in_file.o play.o verify_user_entry.o ranking.o)
LDFLAGS=
EXEC=maze
EXEC2=test

all: $(EXEC) $(EXEC2) doc

${EXEC}: $(OBJ_DIR) ${OBJS}
	mkdir -p obj
	mkdir -p documentation
	mkdir -p files
	mkdir -p files/saves_files
	mkdir -p files/scores_files
	$(CC) ${OBJS} -o $@ ${LDFLAGS}

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

$(OBJ_DIR)/manage_maze_in_file.o: $(SRC_DIR)/manage_maze_in_file.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

$(OBJ_DIR)/play.o: $(SRC_DIR)/play.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

$(OBJ_DIR)/verify_user_entry.o: $(SRC_DIR)/verify_user_entry.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

$(OBJ_DIR)/ranking.o: $(SRC_DIR)/ranking.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

$(OBJ_DIR)/maze_function.o: $(SRC_DIR)/maze_function.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

$(EXEC2): $(OBJ_DIR) $(OBJS_TEST)
	$(CC) ${OBJS} -o $@ ${LDFLAGS}

$(OBJ_DIR)/test_maze.o: $(TEST_DIR)/test_maze.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

$(OBJ_DIR):
	mkdir -p obj

clean:
	rm -f ./obj/*.o core

doc:
	doxygen ./Doxyfile 

help:
	@echo "Usage: make {all|maze|test|clean|doc|help}"