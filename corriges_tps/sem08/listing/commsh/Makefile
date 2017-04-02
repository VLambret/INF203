CC	= gcc
CFLAGS	= -Wall -Wextra -g
BIN	= bin
OBJ	= obj

TARGET  = $(BIN)/supp_comm_sh

all: $(TARGET)

$(TARGET): $(OBJ)/supp_comm_sh.o $(OBJ)/automate.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: %.c automate.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)/* $(BIN)/*
