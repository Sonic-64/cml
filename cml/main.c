#include <stdlib.h>
#include <stdio.h>
#include "cml.h"
int main() {
    int ptr [] = {20,221,61,51,52,66,60,55,69};
    quicksort(ptr,0,9);
    printf("%i %i %i %i %i %i %i %i %i", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4],ptr[5],ptr[6],ptr[7],ptr[8]);
    printf("abcd");
    return 0;
}