#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geometric.h"


int* geometric(int n){
 int len; static int arr[100];

int i;int temp =1;
for(i = 0;i<100;i++){
    *(arr+i) = temp;
    temp = temp*3;

}

return arr;

}
