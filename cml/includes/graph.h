#ifndef GRAPH_H
#include <stdlib.h>
typedef struct AdjListNode {
    int dest;                // Destination node (index of adjacent node)
    struct AdjListNode* next; // Pointer to next adjacent node
} AdjListNode;
typedef struct Node {
    int *cordinates;
    int num_nodes;  
    struct AdjListNode* first;  
} Node;
typedef struct NodeQueue {
double f_cost;
int index;
struct NodeQueue* next;
} NodeQueue;
typedef struct Graph {
int num_dimensions;
int num_nodes;
struct Node *nodes;
} Graph;

Graph *graph_new(int num_nodes,int num_dimensions);
void add_edge(Node *node,int destination);
void deleteEdge(Node *node,int destination);
void node_delete(Node *node);

#define GRAPH_H
#endif