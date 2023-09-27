/**
 * @file graph_test_utils.h
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Vladimir Meciar (xmecia00)
 * @brief This file contains  functions and macros needed for graph_test.c
 * @changes 7.12.2022
 */

#ifndef IAL22_GRAPH_TEST_UTILS_H
#define IAL22_GRAPH_TEST_UTILS_H

#include "graph.h"

#define TESTGRAPH(NAME, DESCRIPTION)                                           \
  void NAME() {                                                                \
    printf("[%s] %s\n", #NAME, DESCRIPTION);                                   \
    Vector *test_graph = Graph_Init(Graph_Destroy);                            \
    printf("\n");

#define ENDTESTGRAPH                                                           \
  printf("\n");                                                                \
  Graph_Destroy(test_graph);                                                   \
  }

/**
* Pretty self explaining :D
*/
void Graph_Init_Test();

/**
 * Print graph
 * @param graph Pointer on graph
 */
void Graph_Print(Vector *graph);

#endif //IAL22_GRAPH_TEST_UTILS_H
