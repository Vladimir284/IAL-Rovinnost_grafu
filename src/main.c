//
// Created by vladimir on 11/23/22.
//

#include "../inc/node_test.h"
#include "../inc/graph_test.h"
#include <string.h>

#define TEST 1

int main(int argc, char *argv[]) {

    if (TEST) {
        if ((argc > 2) || (argc <= 1)) {
            ERROR("Wrong amount of arguments");
        }

        if (strcmp("node", argv[1]) == 0)
            Test_Node();
        else if (strcmp("graph", argv[1]) == 0)
            Test_Graph();

        return 0;
    }
}