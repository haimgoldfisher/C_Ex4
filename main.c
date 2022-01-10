# include <stdio.h>
# include <stdlib.h>
# include "graph.h"

int main()
{
    char curr_char;
    int index = 0;
    //struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    struct Graph g = {0, 0, NULL, NULL};
    struct Graph *graph_ptr = &g;
    scanf(" %c", &curr_char);
    while (curr_char != EOF || curr_char != '\n')
    {
        if (curr_char == 'A') // curr graph removing & new graph building
        {
            // can be 'n' or int
            index++;
            if (graph_ptr->nodes_num > 0)
            {
//                free(graph->head_node);
//                free(graph->head_edge);
//                graph->edges_num=0;
//                graph->nodes_num=0;
                delete_graph(graph_ptr);
            }
            init_graph(graph_ptr, &curr_char);
        }
        else if (curr_char == 'B') // new node adding
        {
            index++;
            int id_to_add;
            scanf(" %d",&id_to_add);
            add_node(id_to_add, graph_ptr);
            int dest, w;
            while (scanf(" %d %d", &dest, &w) == 2)
            {
                connect(id_to_add, dest, w, graph_ptr);
            }
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'D') // node removing (+ relevant edges)
        {
            index++;
            int id_to_remove;
            scanf(" %d",&id_to_remove);
            remove_node(id_to_remove ,graph_ptr);
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'S') // Shortest Path
        {
            index++;
//            int src, dest;
//            if (scanf(" %d %d", &src, &dest) == 2)
//                shortest_path(src, dest, *graph);
//            scanf(" %c", &curr_char);
//            printf("Dijsktra shortest path: %d \n", path);

        }
        else if (curr_char == 'T') // TSP - Traveling Salesman Problem
        {
            index++;
//            struct Node head;
//            int id;
//            while (scanf(" %d", &id) == 1)
//            {
//
//            }
//            TSP(graph);
//            scanf(" %c", &curr_char);
//            printf("TSP shortest path: %d \n", path);

        }
        else if (curr_char == 'E')
        {
            break;
        }
        else if (curr_char == 'P')
        {
            print_graph(graph_ptr);
            scanf(" %c", &curr_char);
        }
    }
    //free(head);
    return 0;
}

//struct Graph g = {0, 0, NULL, NULL};
//struct Graph *ptr_g;
//ptr_g = &g;
//add_node(0, ptr_g);
//add_node(1, ptr_g);
//connect(0, 1, 1, ptr_g);
//connect(1, 0, 1, ptr_g);
//remove_node(0, ptr_g);
