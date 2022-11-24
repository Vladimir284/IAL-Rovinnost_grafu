//
// Created by vladimir on 11/23/22.
//

#include "node_test.h"
#include "graph_test.h"
#include <string.h>

int main(int argc, char *argv[]) {

    if ((argc > 2) || (argc <= 1)) {
        ERROR("Wrong amount of arguments");
        return 1;
    }

    if (strcmp("node", argv[0]) != 0)
        Test_Node();
    else if (strcmp("graph", argv[0]) != 0)
        test_graph();

    return 0;
}