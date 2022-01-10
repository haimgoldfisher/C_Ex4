# include <stdio.h>
# include "graph.h"

int main()
{
    char curr_char; // for scanner
    struct Graph g = {0, 0, NULL, NULL}; // the graph of the program
    struct Graph *graph_ptr = &g; // pointer to the graph
    scanf(" %c", &curr_char); // must be a char
    while (curr_char != EOF || curr_char != '\n') // read until the input has chars
    {
        if (curr_char == 'A') // curr graph removing & new graph building
        {
            if (graph_ptr->nodes_num > 0) // we have a graph - delete it
            {
                delete_graph(graph_ptr);
            }
            init_graph(graph_ptr, &curr_char);
        }
        else if (curr_char == 'B') // new node adding / node update
        {
            int id_to_add;
            scanf(" %d",&id_to_add);
            add_node(id_to_add, graph_ptr); // node adding
            int dest, w;
            while (scanf(" %d %d", &dest, &w) == 2)
            {
                connect(id_to_add, dest, w, graph_ptr); // edges adding
            }
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'D') // node removing (+ relevant edges)
        {
            int id_to_remove;
            scanf(" %d",&id_to_remove);
            remove_node(id_to_remove ,graph_ptr);
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'S') // Shortest Path
        {
            int src, dest, res;
            res = -1;
            if (scanf(" %d %d", &src, &dest) == 2)
                res = shortest_path(src, dest, graph_ptr);
            if (res == 0)
                res = -1;
            printf("Dijsktra shortest path: %d \n", res); // actualy we work with floyd algo
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'T') // TSP - Traveling Salesman Problem
        {
            int ans = -1;
            ans = TSP(graph_ptr, &curr_char);
            printf("TSP shortest path: %d \n", ans);
            scanf(" %c", &curr_char);
        }
        else if (curr_char == 'E') // my EXIT
        {
            break; // for self debug
        }
        else if (curr_char == 'P') // my PRINTER
        {
            print_graph(graph_ptr);
            scanf(" %c", &curr_char);
        }
    }
    free_graph(graph_ptr); // nodes + edges
    return 0;
}

// MAIN()
//struct Graph g = {0, 0, NULL, NULL};
//struct Graph *ptr_g;
//ptr_g = &g;
//add_node(0, ptr_g);
//add_node(1, ptr_g);
//connect(0, 1, 1, ptr_g);
//connect(1, 0, 1, ptr_g);
//remove_node(0, ptr_g);
