CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g -DDEBUG
LDFLAGS=-lm
src=$(wildcard src/*.c)
headers=$(wildcard src/*.h)
obj=$(src:.c=.o)
BIN=ial22

.PHONY: run
all: build clean

# CODE
codeBuild: $(BIN)
$(BIN): $(obj) $(headers)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean: codeClean
	-rm -f $(BIN)

codeClean:
	-rm -f $(obj)

code: codeBuild codeClean

# Execute with arguments: make run ARGS="some arguments"
run: code
	./$(BIN) $(ARGS)

test_node:
	@./cmake-build-debug/ial22 node >node_test_current.output
	@echo "\nTest output differences:"
	@diff -s -U 5 node_test_current.output test/data_structure/node_test_reference.output
	@rm -f node_test_current.output