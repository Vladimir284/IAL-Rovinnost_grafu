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

clean:
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

test_scanner:
	# Write tests here
	@./$(TARGET) scanner <input/graph_Franklin.graph >scanner_test_current.output
	@echo "\nTest output differences:"
	@diff -s -U 5 scanner_test_current.output test/scanner/scanner_name_reference.output
	@rm -f node_test_current.output