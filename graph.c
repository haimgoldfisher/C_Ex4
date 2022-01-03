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

pnode get_node(pnode *head, int node_num)
{
    if (head == NULL) // stop condition
        return NULL;
    pnode this_node = *head;
    if (this_node->node_num == node_num) // stop condition 2
        return this_node;
    return get_node(this_node->next, node_num); // recursive call to next node
}

pnode remove_node(pnode *head, int node_num)
{
    if (head == NULL)
        return NULL;
    pnode this_node = *head;
    while(this_node->next != NULL)
    {
        pnode *next_ptr = this_node->next;
        pnode next_node = *next_ptr;
        if (this_node->node_num == node_num)
        {
            del_node_from_all(*head, this_node->node_num);
            if (next_node != NULL)
                this_node = next_node;
            else
                this_node = NULL;
            free(next_ptr);
            return this_node;
        }
        else if (next_node->node_num == node_num)
        {
            pnode *next_ptr2 = next_node->next;
            pnode next_next_node = *next_ptr2;
            del_node_from_all(*head, this_node->node_num);
            if (*next_ptr2 != NULL)
                this_node->next = next_ptr2;
            else
                this_node->next = NULL;
            free(next_ptr);
            free(next_ptr2);
            return this_node;
        }
        this_node = next_node;
    }
    free(this_node);
    return NULL;
}

void build_graph_cmd(pnode *head)
{

}
void insert_node_cmd(pnode *head)
{

}
void delete_node_cmd(pnode *head)
{

}
void printGraph_cmd(pnode head) //for self debug
{

}
void deleteGraph_cmd(pnode* head)
{

}
void shortsPath_cmd(pnode head)
{

}
void TSP_cmd(pnode head)
{

}