# include "graph.h"
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

Node* get_node(int id, struct Node* head)
{
    if (head == NULL) // stop condition
        return NULL;
    struct Node* curr = head;
    if (curr->key == id) // stop condition 2
        return curr;
    return get_node(id, head->next); // recursive call to next node
}

void remove_src_edges(int id_to_remove, Graph graph) // after remove a node from a graph
{
    struct Edge* curr = graph.head_edge;
    while (curr->next != NULL)
    {
        if (curr->src == id_to_remove)
        {
            remove_edge(curr->src, curr->dest, graph);
            graph.head_edge--;
            curr = graph.head_edge;
        }
        else
        {
            curr = curr->next;
        }
    }
}

void add_node(int id, struct Graph graph)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Node new_node;
    new_node->key = id;
    new_node->next = NULL;
    if (graph.head_node == NULL) // empty list
    {
        graph.head_node = new_node;
        graph.nodes_num++;
        return;
    }
    if (graph.head_node->key == id) // first node has the same key as new node
    {
        remove_src_edges(id, graph); // remove edges FROM this node (not TO)
        return;
    }
    struct Node* curr_node = graph.head_node;
    while (curr_node->next != NULL)
    {
        curr_node = curr_node->next;
        if (curr_node->key == id)  // curr node has the same key as new node
        {
            return;
        }
    }
    curr_node->next = new_node;
    graph.nodes_num++;
}

void remove_relevant_edges(int id_to_remove, Graph graph) // after remove a node from a graph
{
    struct Edge* curr = graph.head_edge;
    while (curr->next != NULL)
    {
        if (curr->src == id_to_remove || curr->dest == id_to_remove)
        {
            remove_edge(curr->src, curr->dest, graph);
            graph.head_edge--;
            curr = graph.head_edge;
        }
        else
        {
            curr = curr->next;
        }
    }
}

void remove_node(int id_to_remove, Graph graph)
{
    if (graph.head_node == NULL)
        return;
    struct Node* this_node = graph.head_node;
    if (this_node->key == id_to_remove)
    {
        graph.head_node = NULL;
        remove_relevant_edges(id_to_remove, graph);
        free(this_node);
        graph.nodes_num = 0;
        return;
    }
    while(this_node->next != NULL)
    {
        struct Node *next_node = this_node->next;
        if (next_node->key == id_to_remove)
        {
            struct Node *next_next_node = next_node->next;
            remove_relevant_edges(id_to_remove, graph);
            if (next_next_node != NULL)
                this_node->next = next_next_node;
            else
                this_node->next = NULL;
            free(next_node);
            free(next_next_node);
            graph.nodes_num--;
            return;
        }
        this_node = next_node;
    }
}


void connect(int src, int dest, int w, Graph graph)
{
    struct Edge* new_edge = (struct Edge*) malloc(sizeof(struct Edge));
    //Edge new_edge;
    new_edge->src = src;
    new_edge->dest = dest;
    new_edge->weight = w;
    new_edge->next = NULL;
    struct Edge* curr = graph.head_edge;
    while (curr->next != NULL)
    {
        if (curr->src == src && curr->dest == dest)
        {
            curr->weight = w; // update new weight and return
            return;
        }
        curr = curr->next;
    }
    curr->next = new_edge;
    graph.edges_num++;
}
void remove_edge(int src, int dest, struct Graph graph) {
    if (graph.head_edge == NULL)
        return;
    struct Edge *this_edge = graph.head_edge;
    if (this_edge->src == src && this_edge->dest == dest) {
        graph.head_edge = NULL;
        free(this_edge);
        graph.edges_num = 0;
        return;
    }
    while (this_edge->next != NULL) {
        struct Edge *next_edge = this_edge->next;
        if (next_edge->src == src && next_edge->dest == dest) {
            struct Edge *next_next_edge = next_edge->next;
            if (next_next_edge != NULL)
                this_edge->next = next_next_edge;
            else
                this_edge->next = NULL;
            free(next_edge);
            free(next_next_edge);
            graph.nodes_num--;
            return;
        }
        this_edge = next_edge;
    }
}

void init_graph(struct Graph *graph, char curr_char)
{
    int nodes_num;
    scanf(" %d", &nodes_num);
    if (nodes_num < 1)
        return;
    struct Node* head = (Node*) malloc((nodes_num * sizeof(Node)));
    scanf(" %c", &curr_char);
    while (curr_char == 'n')
    {
        int node_id;
        scanf(" %d", &node_id);
        add_node(node_id, *graph);
        // for the edges from this node
        int w, dest;
        while (scanf(" %d %d", &dest, &w) == 2)
        {
            connect(node_id, dest, w, *graph);
        }
        scanf(" %c", &curr_char);
    }
}

void print_nodes(struct Node* curr)
{
   while (curr != NULL)
   {
       printf(" %d ", curr->key);
       curr = curr->next;
   }
}

void print_edges(struct Edge* curr)
{
   while (curr != NULL)
   {
       printf(" %d %d %f", curr->src, curr->dest, curr->weight);
       curr = curr->next;
   }
}

void print_graph(struct Graph graph) //for self debug
{
    print_nodes(graph.head_node);
    print_edges(graph.head_edge);
}
void delete_graph(struct Graph graph)
{
    struct Node* node = graph.head_node;
    struct Edge* edge = graph.head_edge;
    while (node != NULL)
    {
        remove_node(node->key, graph);
        node = graph.head_node;
    }
}
void shortest_path(int src, int dest, struct Graph graph)
{

}
void TSP(struct Graph graph)
{

}