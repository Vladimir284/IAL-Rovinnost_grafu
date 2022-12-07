# Makefile
# IAL Náhradní projekt - 05. Rovinnost grafu
# Vladimir Meciar (xmecia00)
# Subor na spustanie cielov pomocou make
# Naposledy upravene 7.12.2022
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

all: clean codeBuild

docBuild:
	latexmk -pdf doc/documentary.tex

openDoc:
	evince documentary.pdf

docClean:
	rm -f documentary.aux
	rm -f documentary.fdb_latexmk
	rm -f documentary.fls
	rm -f documentary.lof
	rm -f documentary.log
	rm -f documentary.lot
	rm -f documentary.out
	rm -f documentary.toc
	rm -f doc/*.aux
	rm -f doc/modules/*.aux

doc: docBuild docClean openDoc

codeBuild: $(OBJECTS)
	$(CC) $(CCFLAGS) $(INCLUDE) $(OBJECTS) -o $(TARGET) $(LIBPATH) $(LIBS)

%.o: ../src/%.c
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

clean: docClean
	rm -rf obj
	rm -f $(TARGET)
	mkdir obj

# Execute with arguments: make run ARGS="some arguments"
run: $(TARGET)
	./$(TARGET) $(ARGS)

test: test_structure test_scanner

test_structure: test_node_structure test_graph_structure

test_node_structure: all
	@# Tests for data structure
	@./$(TARGET) node >node_test_current.output
	@echo "Test output differences:"
	@diff -s -U 5 node_test_current.output test/data_structure/node_test_reference.output
	@rm -f node_test_current.output

test_graph_structure: all
	@./$(TARGET) graph >graph_test_current.output
	@echo "Test output differences:"
	@diff -s -U 5 graph_test_current.output test/data_structure/graph_test_reference.output
	@rm -f graph_test_current.output

test_scanner: all
	./test/scanner_test.sh

pack:
	# TBD