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
    scanf(" %c", &curr_char);
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
            init_graph(graph, curr_char);
        }
        else if (curr_char == 'B') // new node adding
        {
            index++;
            int id_to_add;
            scanf(" %d",&id_to_add);
            add_node(id_to_add, *graph);
            int dest, w;
            while (scanf(" %d %d", &dest, &w) == 2)
            {
                connect(id_to_add, dest, w, *graph);
            }
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'D') // node removing (+ relevant edges)
        {
            index++;
            int id_to_remove;
            scanf(" %d",&id_to_remove);
            remove_node(id_to_remove ,*graph);
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'S') // Shortest Path
        {
            index++;
            int src, dest;
            if (scanf(" %d %d", &src, &dest) == 2)
                shortest_path(src, dest, *graph);
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'T') // TSP - Traveling Salesman Problem
        {
            index++;
            struct Node head;
            int id;
            while (scanf(" %d", &id) == 1)
            {

            }
            TSP(graph);
            scanf(" %c", &curr_char);
        }
    }
    //free(head);
    return 0;
}
