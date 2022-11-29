#include "graph.h"
#include "scanner.h"

int *Edge_Init(int id){
    int *pId = (int*) malloc (sizeof(int));
    *pId = id;
    return pId;

}


//Vector *Scanner_Main(const char *file_name)
void Scanner_Main(Vector *graf)
{
    //inicializace proměnných
    char c;

    /* stav skeneru
    * 0 -> začátek/konec uzlu
    * 1 -> po zapsání uzlu
    * 2 -> po zapsání hrany
    */
    int stav = 0;
    int stav_temp;

    //buffer pro zapsání id
    char buff[20];
    memset(buff,0,strlen(buff));
    //ukazatel do bufferu
    char* id = buff;
    buff[0]='\0';

    int id_temp_int;

    char tempstring1[]="ertice_";
    int tempint1 = sizeof(tempstring1);

    char tempstring2[]="- edge_to_vertice_";
    int tempint2 = sizeof(tempstring2);
    Node *node;



    //procházení souboru
    while ((c = getchar()) != EOF)
    {

        switch (c)
        {
        case 'V':
            if (stav!=0)
            {
                fprintf(stderr,"error špatný formát, na vstupu %c, čeká 'V'\n",c);
            }
            for (int i = 0; i < tempint1-1; i++)
            {
                c = getchar();
                if (c != tempstring1[i])
                {
                    fprintf(stderr,"error špatný formát, na vstupu %c, čeká '%c'\n",c,tempstring1[i]);
                    return NULL;
                }
            }
            //zapsání id uzlu
            while (1)
            {
                c = getchar();
                if (c == '0' ||
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
                    *id++ = c;
                    continue;;

                }else if(c == ':'){
                    c = getchar();
                    if(c == '\n')
                    {
                        c = getchar();
                        id_temp_int = atoi(buff);

                        node = Node_Init(id_temp_int);
                        if (!Graph_Add_Node(graf, node)){

                            fprintf(stderr, "CHYBA volání Graph_Add_Node ve Scanneru\n");
                            return NULL;
                        }
                        //vyprázdnění bufferů
                        memset(buff,0,strlen(buff));
                        id=buff;
                        buff[0]='\0';

                        stav=1;
                        break;
                    }
                }
                fprintf(stderr,"error špatný formát, na vstupu %c\n",c);
                return NULL;
                break;
            }
            

        case ' ':
            if (stav!=1 && stav!=2)
            {
                fprintf(stderr,"error špatný formát, na vstupu |%c| čeká ' '\n",c);
            }
            for (int i = 0; i < tempint2-1; i++)
            {
                c = getchar();
                if (c != tempstring2[i])
                {
                    fprintf(stderr,"error špatný formát, na vstupu %c čeká '%c'\n",c,tempstring2[i]);
                    return NULL;
                }
            }
            //zapsání id hrany
            while (1)
            {
                c = getchar();
                if (c == '0' ||
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
                    *id++ = c;
                    continue;

                }else if(c == '\n'){
                    id_temp_int = atoi(buff);
                    if (!Node_Add_Edge(node, Edge_Init(id_temp_int))){

                        fprintf(stderr, "CHYBA volání Graph_Add_Node ve Scanneru\n");
                        return NULL;
                    }
                    //vyprázdnění bufferů
                    memset(buff,0,strlen(buff));
                    id=buff;
                    buff[0]='\0';

                    stav=2;
                    break;
                }else if(c == ';'){
                    c = getchar();
                    if(c == '\n'){
                        c = getchar();
                        id_temp_int = atoi(buff);

                        if (!Node_Add_Edge(node, Edge_Init(id_temp_int))){

                            fprintf(stderr, "CHYBA volání Graph_Add_Node ve Scanneru\n");
                            return NULL;
                        }
                        
                        //vyprázdnění bufferů
                        memset(buff,0,strlen(buff));
                        id=buff;
                        buff[0]='\0';

                        stav=0;
                        break;
                    }
                }
                return NULL;
                break;
            }
        }
    }
}
