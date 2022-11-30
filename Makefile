TARGET := ial22
SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst src%,obj%, $(patsubst %.c,%.o, $(SOURCES)))

INCLUDE := -I.
LIBPATH :=
LIBS :=

FLAGS := -Wall -Wextra -g -DDEBUG
CCFLAGS := $(FLAGS) -std=c99

CC := gcc

.PHONY: clean

all: codeBuild data_test

codeBuild: $(OBJECTS)
	$(CC) $(CCFLAGS) $(INCLUDE) $(OBJECTS) -o $(TARGET) $(LIBPATH) $(LIBS)

%.o: ../src/%.c
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

clean: docClean
	rm -rf obj/*
	rm -f $(TARGET)

# Execute with arguments: make run ARGS="some arguments"
run: $(TARGET)
	./$(TARGET) $(ARGS)

# TODO Finish adn discuss
runAll: $(TARGET)
	@for file in test/graph
		./$(TARGET) <file

test_structure: $(TARGET)
	@# Tests for data structure
	@./$(TARGET) node >node_test_current.output
	@echo "\nTest output differences:"
	@diff -s -U 5 node_test_current.output test/data_structure/node_test_reference.output
	@rm -f node_test_current.output
	@./$(TARGET) graph >graph_test_current.output
	@echo "\nTest output differences:"
	@diff -s -U 5 graph_test_current.output test/data_structure/graph_test_reference.output
	@rm -f graph_test_current.output

docBuild:
	latexmk -pdf doc/latex/documentary.tex

docClean:
	rm -f documentary.aux
	rm -f documentary.fdb_latexmk
	rm -f documentary.fls
	rm -f documentary.lof
	rm -f documentary.log
	rm -f documentary.lot
	rm -f documentary.out
	rm -f documentary.toc
	rm -f doc/latex/*.aux
	rm -f doc/latex/modules/*.aux

doc: docBuild docClean