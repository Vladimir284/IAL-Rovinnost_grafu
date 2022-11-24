CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -lm
HEADERS=../src/vector.h ../src/node.h ../src/graph.h
SRC_GRAPH=graph_test.c graph_test_utils.c ../src/vector.c ../src/node.c ../src/graph.c
SRC_NODE=node_test.c graph_test_utils.c ../src/vector.c ../src/node.c ../src/graph.c
OBJ_NODE=node_test.o graph_test_utils.o ../src/vector.o ../src/node.o ../src/graph.o
BIN_NODE=ial22testNode
BIN_GRAPH=ial22testGraph

.PHONY: test clean

test_node:
	$(CC) -c $(SRC_NODE) -o $(OBJ_NODE)
	$(CC) $(OBJ_NODE) $(BIN_NODE)

clean:
	rm -f test
