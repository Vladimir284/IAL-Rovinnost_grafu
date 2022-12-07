//
// Created by jakub on 6.12.22.
//

#ifndef IAL_ROVINNOST_GRAF_ALGORITHM_H
#define IAL_ROVINNOST_GRAF_ALGORITHM_H

#include "graph.h"
#include "../inc/graph_test_utils.h"
#include "../inc/node_test_utils.h"
#include "list_algorithm.h"
#define NEWLINE printf("\n")
#define INIT_STACK 10
#define STACK_MAX 1000


//initialization edge
int *Init(int id);
//main algorithm
void algorithm(Vector *graph);


#endif //IAL_ROVINNOST_GRAF_ALGORITHM_H
