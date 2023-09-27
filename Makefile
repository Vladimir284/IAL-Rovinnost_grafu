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

doc: docBuild docClean

codeBuild: $(OBJECTS)
	$(CC) $(CCFLAGS) $(INCLUDE) $(OBJECTS) -o $(TARGET) $(LIBPATH) $(LIBS)

%.o: ../src/%.c
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

clean: docClean
	rm -rf obj
	rm -f $(TARGET)
	mkdir obj

# Execute with arguments: make run ARGS="some arguments"
run: all
	./ial22 <input/graph_16_cell.graph
	./ial22 <input/graph_antenna.graph
	./ial22 <input/graph_Chvatal.graph
	./ial22 <input/graph_antiprism.graph
	./ial22 <input/graph_Franklin.graph
	./ial22 <input/graph_GoddardHenning.graph
	./ial22 <input/graph_Grotzsch.graph
	./ial22 <input/graph_Heawood.graph
	./ial22 <input/graph_K3,3.graph
	./ial22 <input/graph_K5.graph
	./ial22 <input/graph_Lemke.graph
	./ial22 <input/graph_Petersen.graph
	./ial22 <input/graph_sun.graph
	./ial22 <input/graph_Tilley.graph
	./ial22 <input/graph_cross.graph

runAll: all


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

test_graph: all
	./test/graph_test.sh

pack: clean
	mkdir xmazur09
	cp -r doc xmazur09
	cp -r inc xmazur09
	cp -r input xmazur09
	cp -r src xmazur09
	cp -r test xmazur09
	cp documentary.pdf xmazur09
	cp README.md xmazur09
	cp Makefile xmazur09
	zip -r xmazur09.zip xmazur09
	rm -rf xmazur09

