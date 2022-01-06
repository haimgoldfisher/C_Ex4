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

Node* get_node(int id, Node* head)
{
    if (head == NULL) // stop condition
        return NULL;
    Node* curr = head;
    if (curr->key == id) // stop condition 2
        return curr;
    return get_node(id, head->next); // recursive call to next node
}

void add_node(int id, Graph graph)
{
    Node* new_node = (struct Node*) malloc(sizeof(struct Node));
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
        return;
    }
    Node* curr_node = graph.head_node;
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
    Edge* curr = graph.head_edge;
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
    Node* this_node = graph.head_node;
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
        Node *next_node = this_node->next;
        if (next_node->key == id_to_remove)
        {
            Node *next_next_node = next_node->next;
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


void connect(int src, int dest, double w, Graph graph)
{
    Edge* new_edge = (struct Edge*) malloc(sizeof(struct Edge));
    //Edge new_edge;
    new_edge->src = src;
    new_edge->dest = dest;
    new_edge->weight = w;
    new_edge->next = NULL;
    Edge* curr = graph.head_edge;
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
void remove_edge(int src, int dest, Graph graph) {
    if (graph.head_edge == NULL)
        return;
    Edge *this_edge = graph.head_edge;
    if (this_edge->src == src && this_edge->dest == dest) {
        graph.head_edge = NULL;
        free(this_edge);
        graph.edges_num = 0;
        return;
    }
    while (this_edge->next != NULL) {
        Edge *next_edge = this_edge->next;
        if (next_edge->src == src && next_edge->dest == dest) {
            Edge *next_next_edge = next_edge->next;
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

Graph init_graph()
{
    return NULL;
}

void print_nodes(Node* curr)
{
   while (curr != NULL)
   {
       printf(" %d ", curr->key);
       curr = curr->next;
   }
}

void print_edges(Edge* curr)
{
   while (curr != NULL)
   {
       printf(" %d %d %f", curr->src, curr->dest, curr->weight);
       curr = curr->next;
   }
}

void print_graph(Graph graph) //for self debug
{
    print_nodes(graph.head_node);
    print_edges(graph.head_edge);
}
void delete_graph(Graph graph)
{
    Node* node = graph.head_node;
    Edge* edge = graph.head_edge;
    while (node != NULL)
    {
        remove_node(node->key, graph);
        node = graph.head_node;
    }
}
void shortest_path(int src, int dest, Graph graph)
{

}
void TSP(Graph graph)
{

}