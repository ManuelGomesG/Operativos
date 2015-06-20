#include "randn.h"
#include <stdlib.h>


int* randn(int n, int l){
    int *r=malloc(n * sizeof *r);

    int i;
    for ( i=0; i<n; i++){
        r[i]=rand() % l;
        r[i]++;
        }
    return r;
}