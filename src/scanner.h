
#ifndef IAL22_SCANNER_H
#define IAL22_SCANNER_H

#include "graph.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief reads file on adress file_name and returns it as graph
 * 
 * @param file_name adress of read file
 * @return Vector*  the graph on output
 */
Vector *Scanner_Main(const char *file_name);

#endif //IAL22_SCANNER_H
