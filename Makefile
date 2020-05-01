.PHONY: clean all run_geometry run_testing
FLAGS := -std=c99
FLAG := -std=c11
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build
all: $(BIN_DIR)/geometry

$(BIN_DIR)/geometry:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/input_handle.o  $(OBJ_DIR)/intersection.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/input_handle.o  $(OBJ_DIR)/intersection.o -o $(BIN_DIR)/geometry -lm $(FLAGS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o $(FLAGS)

$(OBJ_DIR)/input_handle.o: $(SRC_DIR)/input_handle.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/input_handle.c -o  $(OBJ_DIR)/input_handle.o -lm $(FLAGS)

$(OBJ_DIR)/intersection.o: $(SRC_DIR)/intersection.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/intersection.c -o  $(OBJ_DIR)/intersection.o $(FLAGS)


clean:
	rm $(OBJ_DIR)/*.o	
	rm $(BIN_DIR)/geometry
	

run_geometry:
	$(BIN_DIR)/geometry