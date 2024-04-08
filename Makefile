CC=gcc
CFLAGS=-Iinclude
DEPS = include/ui.h
OBJ = src/ui.o src/main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

todo_list: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) todo_list