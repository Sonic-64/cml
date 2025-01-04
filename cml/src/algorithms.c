
#include "algorithms.h"
void swap(int *p,int *q)
{
    int tmp;
    tmp = *p; 
    *p=*q;    
    *q=tmp;   
}
void quicksort( int *table, int l, int r )
{   if((r+l)<2){
    return ;
}
    int i = l;
    int j = r;
    int x = table[( l + r ) / 2 ];
    do
    {
        while( table[ i ] < x )
             i++;
       
        while( table[ j ] > x )
             j--;
       
        if( i <= j )
        {
            swap( &table[ i ], &table[ j ] );
           
            i++;
            j--;
        }
    } while( i < j );
   
    if( l < j ) quicksort( table, l, j );
   
    if( r > i ) quicksort( table, i, r );
   
}
void bubblesort(int *table ,int l ){
uint8_t swapped = 1;
while(swapped){
for(int i = 0 ; i < l - 1 ; i++){
    swapped = 0;
if(table[i]>table[i+1])
{
    swap(&table[i],&table[i+1]);
    swapped = 1;
}
}
}
}
double sigmoid(double x){

    return (1/(1+exp(-x)));
}
double derivative ( double(*f)(double*,int),double *x,int respect_to,int num_arguments){
double delta = 1.0e-14;
double original_value = x[respect_to];
x[respect_to] += delta;
double r2 = f(x,num_arguments);
x[respect_to] = original_value;
double r1 = f(x,num_arguments);
return (r2-r1)/delta;
}

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

double euclidean_distance(int *p1,int *p2,int num_dimensions){
double euclidean_distance = 0 ;
int x = 0;

for(int i = 0 ; i < num_dimensions ; i++){
x = p1[i] - p2[i];
x = x * x ;
euclidean_distance += x ;
}
return sqrt(euclidean_distance);
}
double manhattan_distance(int *p1, int*p2 , int num_dimensions){
double manhattan_distance =0;
double x;
for(int i = 0 ; i < num_dimensions ; i++){
x = p1[i] - p2[i];
x = x * x ;
x = sqrt(x);
manhattan_distance += x ;
}
return manhattan_distance;
}


