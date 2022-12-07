/**
 * @file main.c
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Vladimir Meciar (xmecia00)
 * @brief Main file that starts whole process
 * @changes 07.12.2022
 */

#include "../inc/node_test.h"
#include "../inc/graph_test.h"
#include "../inc/test_scanner.h"
#include "../inc/test_algorithm.h"

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
        else if (strcmp("scanner",argv[1]) == 0)
            Test_Scanner();
        else if (strcmp("algorithm", argv[1]) == 0)
            test_algorithm();
        return 0;
    }
}
