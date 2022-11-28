//
// Created by vladimir on 11/20/22.
//

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
