# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "graph.h"

int main()
{
    int i; // index
    char currChar;
    currChar = getchar();
    while (currChar != EOF || currChar != '\n')
    {
        if (currChar == 'A') // curr graph removing & new graph building
        {
            delete_graph();
            init_graph();
        }
        else if (currChar == 'B') // new node adding
        {
            add_node();
        }
        else if (currChar == 'D') // node removing (+ relevant edges)
        {
            remove_node();
        }
        else if (currChar == 'S') // Shortest Path
        {
            shortest_path();
        }
        else if (currChar == 'T') // TSP - Traveling Salesman Problem
        {
            TSP();
        }
    }
    //free(head);
    return 0;
}
