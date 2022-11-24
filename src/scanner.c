//#include "graph.h"

#include "scanner.h"


/**
 * @brief analizuje znak a stav, vyhodí hodnotu změněného stavu v závyslosti na znaku
 * 
 * @param c analyzovaný znak
 * @param stav právě probýhaný znak
 * @return int //stav
 *          -1 -> CHYBA 
 *          0 -> bílý znak (ostatní nebílé znaky)
 * 
 *          1 -> nový uzel //(znak ":")
 *          2 -> zápis id uzlu (znak "[0-9]")
 * 
 *          3 -> nová hrana (znak "-")
 *          4 -> zápis id hrany (znak "[0-9]")
 *          5 -> zápis id hrany (znak ";")
 */
int Symbol_Analyze(char c, int stav) {
    //kontrola vstupu
    /*
    if(&stav == NULL){
        fprintf(stderr, "CHYBA volání Symbol_Analyze stav je NULL\n");
        return -1;
    }

    else*/ if (stav > 5 || stav < 0)
    {
        fprintf(stderr, "CHYBA volání Symbol_Analyze neexistující stav: %d\n",stav);
        return -1;
    }
    
    //znak je středník ";"
    else if (c == ';')
    {
        return 5;
    }
    //znak je dvojtečka ":"
    else if ((c == ':') && (stav == 2))
    {
        return 1;
    }
    
    
    //znak je pomlčka "-"
    else if (c == '-' )
    {
        if (stav==4)
        {
            return 3;
        }
        if (stav==1)
        {
            return 0;
        }
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
        if (stav == 5 || stav == 2)
        {
            return 2;
        }
        //id hrany
        if (stav == 1 || stav == 4 || stav == 3)
        {
            return 4;
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
    return -1;
}

//Vector *Scanner_Main(const char *file_name)
char *Scanner_Main(const char *file_name)
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
    int stav = 5;
    int stav_temp;

    //buffer pro zapsání id
    char buff[20];
    memset(buff,0,strlen(buff));
    //ukazatel do bufferu
    char* id = buff;
    buff[0]='\0';

    int id_temp_int;
    //Node *node;
    //Vector *graf = Graph_Init();
    char *graf="";
    FILE *file_pointer = fopen(file_name, "r");



    //procházení souboru
    while ((c = fgetc(file_pointer)) != EOF)
    {
        //fprintf(stdout,"c=|%c|\n",c);
        //fprintf(stdout,"stav=|%d|\n",stav);

        //určíme stav podle znaku 
        stav_temp = Symbol_Analyze(c, stav);
        fprintf(stdout,"stav_temp=%d\n",stav_temp);
        //bílý znak
        if (stav_temp == 0)
        {
            continue;
        }

        //nebílý znak
        else if(stav_temp != 0)
        {
            stav=stav_temp;
        }
        //neznámí znak nebo stav
        if (stav < 0)
        {
            fprintf(stdout,"error %d<0\n",stav);
            fclose(file_pointer);
            return NULL;
        }
        //nový uzel grafu
        else if (stav == 1)
        {
            //fprintf(stdout,"stav==%d<0\n",stav);
            //const char * id_temp_char = buff;

            id_temp_int = atoi(buff);

            //fprintf(stdout,"stav==%d<0\n",stav);

            //node = Node_Init(id_temp_int);
            fprintf(stdout,"Graph_Add_Node=%d\n",id_temp_int);
            /*
            if (!Graph_Add_Node(graf, node)){
                fprintf(stderr, "CHYBA volání Graph_Add_Node ve Scanneru\n");
                fclose(file_pointer);
                return NULL;
            }*/
            fprintf(stdout,"new_node->%s\n",buff);
            //vyprázdnění bufferu
            memset(buff,0,strlen(buff));
            id=buff;
            buff[0]='\0';
        }
        //id uzlu
        else if (stav == 2)
        {
            //fprintf(stdout,"c->%c\n",c);
            //fprintf(stdout,"id->%s\n",id);
            //strncat(id, &c, 1);
            *id++ = c;
            fprintf(stdout,"new_node_id=%s\n",buff);
            //fprintf(stdout,"hej hej\n");
            //fprintf(stdout,"id->%s\n",id);
            //fprintf(stdout,"buffer->%s\n",buff);
        }
        //nová hrana uzlu
        else if (stav == 3)
        {
            id_temp_int = atoi(buff);
            fprintf(stdout,"Node_Add_Edge->%d\n",id_temp_int);
            /*if (!Node_Add_Edge(node, &id_temp_int)){
                fprintf(stderr, "CHYBA volání Node_Add_Edge ve Scanneru\n");
                fclose(file_pointer);
                return NULL;
            }*/
            fprintf(stdout,"new_edge->%s\n",buff);
            //vyprázdnění bufferu
            memset(buff,0,strlen(buff));
            id=buff;
            buff[0]='\0';
        }
        //id hrany
        else if (stav == 4)
        {
            *id++ = c;
            fprintf(stdout,"new_edge_id->%s\n",buff);
        }
        //konec uzlu
        else if (stav == 5)
        {
            id_temp_int = atoi(buff);
            fprintf(stdout,"Node_Add_Edge->%d\n",id_temp_int);
            /*if (!Node_Add_Edge(node, &id_temp_int)){
                fprintf(stderr, "CHYBA volání Node_Add_Edge ve Scanneru\n");
                fclose(file_pointer);
                return NULL;
            }*/
            fprintf(stdout,"new_edge->%s\n",buff);
            //vyprázdnění bufferu
            memset(buff,0,strlen(buff));
            id=buff;
            buff[0]='\0';
        }
        
        

        
    }
    fclose(file_pointer);
    return graf;
 }

 int main()
 {
    char *graf = Scanner_Main("./text.txt");
    (void)graf;
    fprintf(stdout,"--%s\n",graf);
    return 0;
 }
 


