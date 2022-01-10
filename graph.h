#ifndef GRAPH_H
#define GRAPH_H

//typedef struct GRAPH_NODE_ *pnode;
//
//typedef struct edge_ {
//    int weight;
//    pnode endpoint;
//    struct edge_ *next;
//} edge, *pedge;
//
//
//typedef struct GRAPH_NODE_ {
//    int node_num;
//    pedge edges;
//    pnode *next;
//} node, *pnode;

//

typedef struct Node {
    int key;
    struct Node* next; // for linked list
} Node;

typedef struct Edge {
    int src;
    int weight;
    int dest;
    struct Edge* next; // for linked list
} Edge;

typedef struct Graph {
    int nodes_num;
    int edges_num;
    struct Node* head_node; // linked list of nodes
    struct Edge* head_edge; // linked list of edges
} Graph;

//

void add_node(int, struct Graph*);
void remove_node(int, struct Graph*);
void connect(int, int, int, struct Graph*);
void remove_edge(int, int, struct Graph*);
void init_graph(struct Graph*, char*);
void print_graph(struct Graph*);
void delete_graph(struct Graph*);
void shortest_path(int, int, struct Graph*);
void TSP(struct Graph*);


//void build_graph_cmd(pnode *head);
//void insert_node_cmd(pnode *head);
//void delete_node_cmd(pnode *head);
//void printGraph_cmd(pnode head); //for self debug
//void deleteGraph_cmd(pnode* head);
//void shortsPath_cmd(pnode head);
//void TSP_cmd(pnode head);

#endif
