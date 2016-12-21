CC = gcc
CFLAGS = -Wall -pedantic -ggdb
EXEC_NAME = d_linked_list.exe
OBJ_FILES = doubly_linked_list.o main.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(CFLAGS) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ_FILES) $(EXEC_NAME)
