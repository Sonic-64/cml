
#include "graph.h"
Graph *graph_new(int num_nodes,int num_dimensions){
Graph *g = malloc(sizeof(Graph));
g->num_nodes = num_nodes;
g->num_dimensions = num_dimensions;
g->nodes = calloc(num_nodes,sizeof(Node));
return g;
}

void add_edge(Node *node,int destination){
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = destination;
    newNode->next = node->first;
    node->first = newNode;
}
void deleteEdge(Node *node,int destination){
    AdjListNode* current = node->first;
    AdjListNode* tmp = NULL;

    while (current != NULL && current->dest != destination) {
        tmp = current;         
        current = current->next; 
    }
    if (current == NULL) {
        
        return;
    }

    
    if (tmp == NULL) {
        node->first = current->next;
    } else {
        tmp->next = current->next;        
    }


    free(current);
}

void node_delete(Node *node){
    AdjListNode *current = node->first;
    AdjListNode *tmp;
while (current != NULL) {
        tmp = current;
        current = current->next;
        
        free(tmp);
    }
    free(node->cordinates);
}