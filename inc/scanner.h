#ifndef IAL22_SCANNER_H
#define IAL22_SCANNER_H

#include "graph.h"

/**
 * @brief reads file from stdin and places all the data into graf that is got from pointer
 * 
 * @param graf pointer to graph structure where data will be placed
 * @return bool false if something went wrong
 */
bool Scanner_Main(Vector *graf);

#endif //IAL22_SCANNER_H
