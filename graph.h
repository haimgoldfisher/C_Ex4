#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    pnode *next;
} node, *pnode;

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

void add_node(int id, struct Graph graph);
void remove_node(int id, struct Graph graph);
void connect(int src, int dest, int w, struct Graph graph);
void remove_edge(int src, int dest, struct Graph graph);
void init_graph(struct Graph *graph, char curr_char);
void printGraph(struct Graph graph);
void delete_graph(struct Graph graph);
void shortest_path(int src, int dest, struct Graph graph);
void TSP(struct Graph graph);


void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
