#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void swap(TYPE *p,TYPE *q)
{
    TYPE tmp;
    tmp = *p; 
    *p=*q;    
    *q=tmp;   
}
void quicksort( TYPE table[], TYPE l, TYPE r )
{   if((r+l)<2){
    return ;
}
    TYPE i = l;
    TYPE j = r;
    TYPE x = table[( l + r ) / 2 ];
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
void bubblesort(TYPE table [],TYPE l ){
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

