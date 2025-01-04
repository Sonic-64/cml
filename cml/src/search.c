#include "search.h"


int is_in_queue(NodeQueue *a,int src){
    while(a!=NULL){
    if(a->index==src)
    return 1;
    a = a->next;
    }
    return 0;
}
void enqueue(NodeQueue **set,int src,double f){
NodeQueue *tmp = calloc(1,sizeof(NodeQueue));
tmp->f_cost = f;
tmp->index = src;
if (*set == NULL || (*set)->f_cost>f){
    tmp->next = *set;
    *set = tmp;
}
NodeQueue* current = *set;
    while (current->next != NULL && current->next->f_cost <= f) {
        current = current->next;
    }
    tmp->next = current->next;
    current->next = tmp;
}
int dequeue(NodeQueue **set){
if(*set == NULL){
    return -1;
}
 NodeQueue* temp = *set;
    int nodeIndex = temp->index;
    *set = (*set)->next;
    free(temp);
    return nodeIndex;
}
int *a_star(int start,int goal,Graph *g){
double f;
int parent,z;
NodeQueue *open_list = NULL;

int *came_from = malloc(g->num_nodes * sizeof(int));
for (int i = 0 ; i < g->num_nodes ; i++){
    came_from[i] = -1;
}
double *dist = calloc(g->num_nodes,sizeof(double));
f = euclidean_distance(g->nodes[start].cordinates,g->nodes[goal].cordinates,g->num_dimensions);
enqueue(&open_list,start,f);
while(open_list !=NULL){
 
  parent = dequeue(&open_list);
 AdjListNode *close = g->nodes[parent].first;

 while(close != NULL){
    
    z = close->dest;
    
    if(came_from[z]==-1){
    came_from[z] = parent;
    dist[z] = dist[parent] + euclidean_distance(g->nodes[z].cordinates,g->nodes[parent].cordinates,g->num_dimensions);
 f = dist[z] + euclidean_distance(g->nodes[z].cordinates,g->nodes[goal].cordinates,g->num_dimensions);
 enqueue(&open_list,z,f);
close = close->next;
 if(z == goal ){
    free(dist);
    free(open_list);
    
    return came_from;
  }
    }
 }
}
return NULL;
}
