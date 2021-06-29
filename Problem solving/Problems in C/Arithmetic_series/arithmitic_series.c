#include <stdio.h>
#include <stdlib.h>

int* ar_series(int n){
int i; static arr[100]; int j = 1; int k = 3;int m = 1;
for(i =0;i<=n;i+=2){
    arr[i] = m;
     m+=4;
    arr[j] = k;
    k+=4; j+=2;
}
return arr;
}
