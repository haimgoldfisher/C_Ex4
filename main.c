# include <stdio.h>
# include "graph.h"

int main()
{
    char curr_char;
    struct Graph g = {0, 0, NULL, NULL};
    struct Graph *graph_ptr = &g;
    curr_char = getchar();
    while (curr_char != EOF && curr_char != '\n')
    {
        if (curr_char == 'A') // curr graph removing & new graph building
        {
            if (graph_ptr->nodes_num > 0)
            {
                delete_graph(graph_ptr);
            }
            init_graph(graph_ptr, &curr_char);
        }
        else if (curr_char == 'B') // new node adding
        {
            int id_to_add;
            scanf(" %d",&id_to_add);
            add_node(id_to_add, graph_ptr);
            int dest, w;
            while (scanf(" %d %d", &dest, &w) == 2)
            {
                connect(id_to_add, dest, w, graph_ptr);
            }
            curr_char = getchar();
        }
        else if (curr_char == 'D') // node removing (+ relevant edges)
        {
            int id_to_remove;
            scanf(" %d",&id_to_remove);
            remove_node(id_to_remove ,graph_ptr);
            curr_char = getchar();
        }
        else if (curr_char == 'S') // Shortest Path
        {
            int src, dest, res;
            res = -1;
            if (scanf(" %d %d", &src, &dest) == 2)
                res = shortest_path(src, dest, graph_ptr);
            if (res == 0)
                res = -1;
            printf("Dijsktra shortest path: %d \n", res);
            curr_char = getchar();
        }
        else if (curr_char == 'T') // TSP - Traveling Salesman Problem
        {
            int ans = -1;
            ans = TSP(graph_ptr, &curr_char);
            printf("TSP shortest path: %d \n", ans);
            curr_char = getchar();
        }
        else if (curr_char == 'P') // Printer for debug
        {
            print_graph(graph_ptr);
            curr_char = getchar();
        }
        else if (curr_char == ' ')
            curr_char = getchar();
    }
    free_graph(graph_ptr);
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
