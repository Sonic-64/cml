#ifndef SEARCH_H
#include "graph.h"
#include "algorithms.h"
int is_in_queue(NodeQueue *a,int src);
void enqueue(NodeQueue **set,int src,double f);
int dequeue(NodeQueue **set);
int *a_star(int start,int goal,Graph *g);
#define SEARCH_H
#endif