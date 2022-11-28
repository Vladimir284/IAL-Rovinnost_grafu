//
// Created by vladimir on 11/21/22.
//

#ifndef IAL22_NODE_TEST_UTILS_H
#define IAL22_NODE_TEST_UTILS_H

#include "node.h"

#define TESTNODE(NAME, DESCRIPTION)                                           \
  void NAME() {                                                                \
    printf("[%s] %s\n", #NAME, DESCRIPTION);                                   \
    Node *test_node = Node_Init((int) node_id);                                \
    printf("\n");

#define ENDTESTNODE                                                            \
  printf("\n");                                                                \
  Node_Destroy(test_node);                                                     \
  }

/**
 * Speaks for itself :D
 */
void Node_Init_Test();

/**
 * Print edges of node
 * @param node Pointer on node
 */
void Node_Print_Edges(Node *node);

/**
 * Print flags of node
 * @param node Pointer on node
 */
void Node_Print_Flags(Node *node);

/**
 * Print id, flags and edges of node
 * @param node Pointer on allocated node
 */
void Node_Print(Node *node);

#endif //IAL22_NODE_TEST_UTILS_H
