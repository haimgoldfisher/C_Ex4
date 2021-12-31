# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "graph.h"

int main()
{
    int i; // index
    char currChar;
    char* ptr = (char *) malloc(sizeof(char));
    currChar = getchar();
    while (currChar != '\0')
    {
        if (currChar == 'A') // curr graph removing & new graph building
        {
            deleteGraph_cmd();
            build_graph_cmd();
        }
        if (currChar == 'B') // new node adding
        {
            insert_node_cmd();
        }
        if (currChar == 'D') // node removing (+ relevant edges)
        {
            delete_node_cmd();
        }
        if (currChar == 'S') // Shortest Path
        {
            shortsPath_cmd();
        }
        if (currChar == 'T') // TSP - Traveling Salesman Problem
        {
            TSP_cmd();
        }
    }
    free(ptr);
    return 0;
}
