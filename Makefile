CC=gcc
CFLAGS=-I.
DEPS = ui.h
OBJ = src/ui.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

todo_list: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) todo_list