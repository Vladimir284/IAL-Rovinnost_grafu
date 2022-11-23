#include "graph.h"

#include "scanner.h"


/**
 * @brief analizuje znak a stav, vyhodí hodnotu změněného stavu v závyslosti na znaku
 * 
 * @param c analyzovaný znak
 * @param stav právě probýhaný znak
 * @return int //stav
 *          -1 -> CHYBA 
 *          0 -> špatný znak (ostatní nebílé znaky)
 * 
 *          1 -> nový uzel (znak ";")
 *          2 -> zápis id uzlu (znak "[0-9]")
 * 
 *          3 -> nová hrana (znak "-")
 *          4 -> zápis id hrany (znak "[0-9]")
 */
int Symbol_Analyze(char c, int stav) {
    //kontrola vstupu
    if(&stav == NULL){
        fprintf(stderr, "CHYBA volání Symbol_Analyze stav je NULL\n");
        return -1;
    }

    else if (stav > 4 || stav < 0)
    {
        fprintf(stderr, "CHYBA volání Symbol_Analyze neexistující stav: %d\n",stav);
        return -1;
    }
    
    //znak je středník ";"
    else if (c == ';')
    {
        return 1;
    }
    
    //znak je pomlčka "-"
    else if (c == '-')
    {
        return 3;
    }

    //znak je číslo
    else if (c == '0' ||
        c == '1' ||
        c == '2' ||
        c == '3' ||
        c == '4' ||
        
        c == '5' ||
        c == '6' ||
        c == '7' ||
        c == '8' ||
        c == '9' )
    {
        //id uzlu
        if (stav == 1 || stav == 2)
        {
            return 2;
        }
        //id hrany
        if (stav == 3 || stav == 4)
        {
            return 3;
        }
    }

    //bílé znaky
    else if (c == ' ' || c == '\n')
    {
        return 0;
    }

    //neznámé znaky
    else {
        fprintf(stderr, "CHYBA Soubor obsahuje neznámý znak: \"%c\"\n",c);
        return -1;
    }
    

}


Vector *Scanner_Main(const char *file_name)
 {
    //inicializace proměnných
    char c;

    /* stav skeneru
    * 0 -> bílý znak
    * 1 -> nový uzel (znak ";")
    * 2 -> zápis id uzlu (znak "[0-9]")
    * 3 -> nová hrana (znak "-")
    * 4 -> zápis id hrany (znak "[0-9]")
    */
    int stav = 1;
    int stav_temp;
    char* id;
    int id_temp_int;
    Node *node;
    Vector *graf = Graph_Init();
    FILE *file_pointer = fopen(file_name, "r");



    //procházení souboru
    while ((c = fgetc(file_pointer)) != EOF)
    {
        //určíme stav podle znaku 
        stav_temp = Symbol_Analyze(c, stav);
        //nebílý znak
        if (stav == 0)
        {
            stav = stav_temp;
        }
        //neznámí znak nebo stav
        else if (stav < 0)
        {
            fclose(file_pointer);
            return NULL;
        }
        //nový uzel grafu
        else if (stav == 1)
        {
            id_temp_int = atoi(id);
            node = Node_Init(id_temp_int);
            //fprintf(stdout,"new_node=%d\n",id_temp_int);

            if (!Graph_Add_Node(graf, node)){
                fprintf(stderr, "CHYBA volání Graph_Add_Node ve Scanneru\n");
                fclose(file_pointer);
                return NULL;
            }
        }
        //id uzlu
        else if (stav == 2)
        {
            strncat(id, &c, 1);
            //fprintf(stdout,"new_node_id->%s\n",id);
        }
        //nová hrana uzlu
        else if (stav == 3)
        {
            id_temp_int = atoi(id);
            //fprintf(stdout,"new_edge->%d\n",id_temp_int);
            if (!Node_Add_Edge(node, &id_temp_int)){
                fprintf(stderr, "CHYBA volání Node_Add_Edge ve Scanneru\n");
                fclose(file_pointer);
                return NULL;
            }
        }
        //id hrany
        else if (stav == 4)
        {
            strncat(id, &c, 1);
            //fprintf(stdout,"new_edge_id->%s\n",id);
        }
        
        

        
    }
    fclose(file_pointer);
    return graf;
 }


