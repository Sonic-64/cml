#ifndef ALGORITHMS_H
#include <math.h>
#include <stdlib.h>
typedef struct point {
    int group;
    int *cordinates;
}point;
typedef struct data {
    int num_dimensions;
    int num_points;
    point *Points;
}data;
void swap(int *p,int *q);
void quicksort( int table[], int l, int r );
void bubblesort(int table [],int l );
double sigmoid(double x);
double ReLU(double x);
double derivative ( double(*f)(double*,int),double *x,int respect_to,int num_arguments);
int mode(int *arr,int num_elements);
double euclidean_distance(int *p1,int *p2,int num_dimensions);
double manhattan_distance(int *p1,int *p2,int num_dimensions);


#define ALGORITHMS_H
#endif
