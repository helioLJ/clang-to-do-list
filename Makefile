CC=gcc
CFLAGS=-Iinclude
LDFLAGS = -lcunit
DEPS = include/ui.h
OBJ = src/ui.o src/main.o
TEST_SRC = tests/test_ui.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_EXEC = test_ui

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

todo_list: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TEST_EXEC): src/ui.o $(TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean test

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -f $(OBJ) todo_list $(TEST_OBJ) $(TEST_EXEC)