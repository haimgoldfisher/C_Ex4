# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "graph.h"

int main()
{
    int i; // index
    char currChar;
    pnode* head = (pnode *) malloc(sizeof(pnode));
    currChar = getchar();
    while (currChar != EOF || currChar != '\n')
    {
        if (currChar == 'A') // curr graph removing & new graph building
        {
            deleteGraph_cmd(head);
            build_graph_cmd(head);
        }
        else if (currChar == 'B') // new node adding
        {
            insert_node_cmd(head);
        }
        else if (currChar == 'D') // node removing (+ relevant edges)
        {
            delete_node_cmd(head);
        }
        else if (currChar == 'S') // Shortest Path
        {
            shortsPath_cmd();
        }
        else if (currChar == 'T') // TSP - Traveling Salesman Problem
        {
            TSP_cmd();
        }
    }
    free(head);
    return 0;
}
