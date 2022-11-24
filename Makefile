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

