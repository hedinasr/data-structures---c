CC = gcc
CFLAGS = -Wall -pedantic -ggdb
EXEC_NAME = sl.exe
OBJ_FILES = skip_list.o object.o main.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(CFLAGS) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ_FILES) $(EXEC_NAME)
