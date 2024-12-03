#include <math.h>
#include <stdlib.h>
#include "sort.h"
#include "types.h"



int mode(int *arr,int num_elements){
int i,j ;
int count,max_count,max_index;
max_count = 0;
max_index = 0;
for( i = 0 ; i< num_elements ;i++ ){
count = 0 ;
for(j = 0 ; j <num_elements ; j++){
if(arr[j]==arr[i])
count ++;
}
if(count > max_count){
    max_count = count;
    max_index = i ;
}
}

return arr[max_index];
}
double get_distance(point p1,point p2,int num_dimensions){
double euclidean_distance = 0 ;
int x;

for(int i = 0 ; i < num_dimensions ; i++){
x = p1.dimension[i] - p2.dimension[i];
x = x * x ;
euclidean_distance += x ;
}
return sqrt(euclidean_distance);
}
int knn(point Point , data  *Dataset ,int num_neighbours){

double *dist = (double*)calloc(num_neighbours, sizeof(double));
int *category = (int*)calloc(num_neighbours ,sizeof(int));
int i,j;
double x;
int result;
for(i = 0 ; i < Dataset->num_points ; i++){
x = get_distance(Point,Dataset->Points[i],Dataset->num_dimensions);
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