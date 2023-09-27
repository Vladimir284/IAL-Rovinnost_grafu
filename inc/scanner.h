/**
 * @file scanner.h
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Ondřej Podroužek (xpodro03)
 * @brief This file reads graph file from stdin in percise format and writes it in given Vector structure.
 * @changes 07.12.2022
 */

#ifndef IAL22_SCANNER_H
#define IAL22_SCANNER_H

#include "graph.h"

/**
 * @brief reads file from stdin and places all the data into Vector structure
 * 
 * @param graf pointer to Vector structure where data will be placed
 * @return false, and Error message, if something went wrong and true if nothing went wrong.
 */
bool Scanner_Main(Vector *graf);

#endif //IAL22_SCANNER_H
