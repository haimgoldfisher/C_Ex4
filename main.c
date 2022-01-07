# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "graph.h"

int main()
{
    char curr_char;
    int index = 0;
//    struct Graph graph;
    struct Graph * graph = (struct Graph*) malloc(sizeof(struct Graph));
    scanf("%c", &curr_char);
    while (curr_char != EOF || curr_char != '\n')
    {
        if (curr_char == 'A') // curr graph removing & new graph building
        {
            // can be 'n' or int
            index++;
            if (index > 1)
            {
//                free(graph->head_node);
//                free(graph->head_edge);
//                graph->edges_num=0;
//                graph->nodes_num=0;
                delete_graph(*graph);
            }
            init_graph(graph);
        }
        else if (curr_char == 'B') // new node adding
        {
            index++;
            int id_to_add;
            while ()
            {
                scanf("%d",&id_to_add);
                add_node(id_to_add, *graph);
            }
        }
        else if (curr_char == 'D') // node removing (+ relevant edges)
        {
            index++;
            int id_to_remove;
            while ()
            {
                scanf("%d",&id_to_remove);
                remove_node(id_to_remove ,*graph);
            }
        }
        else if (curr_char == 'S') // Shortest Path
        {
            index++;
            shortest_path(graph);
        }
        else if (curr_char == 'T') // TSP - Traveling Salesman Problem
        {
            index++;
            TSP(graph);
        }
        scanf("%c", &curr_char); // the menu after we made our first function choose
    }
    //free(head);
    return 0;
}
