#ifndef TYPES_H
typedef int TYPE;
typedef struct matrix {
    int rows;
    int columns;
    int *data;
}matrix;

typedef struct point {
    int group;
    int *dimension;
}point;

typedef struct data {
    int num_dimensions;
    int num_points;
    point *Points;
}data;

#define TYPES_H
#endif