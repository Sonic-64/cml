#include "classify.h"
int knn(point *Point , data  *Dataset ,int num_neighbours){

double *dist = (double*)calloc(num_neighbours, sizeof(double));
int *category = (int*)calloc(num_neighbours ,sizeof(int));
int i,j;
double x;
int result;
for(i = 0 ; i < Dataset->num_points ; i++){
x = euclidean_distance(Point->cordinates,Dataset->Points[i].cordinates,Dataset->num_dimensions);
for(j=0 ; j < num_neighbours ; j++)
{
if(x<dist[j]){
    dist[j] = x;
    category[j] = Dataset->Points[i].group;
}
}

}
result = mode(category,num_neighbours);
free(dist);
free(category);
return result;
}