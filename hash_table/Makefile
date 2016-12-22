CC = gcc
CFLAGS = -Wall -pedantic -ggdb
EXEC_NAME = hash_table.exe
OBJ_FILES = hash_table.o ../utils/date.o main.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(CFLAGS) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ_FILES) $(EXEC_NAME)
