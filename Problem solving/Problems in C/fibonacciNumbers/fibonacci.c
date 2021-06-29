#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"
void fibo(int n){
// with foor loop
int i; int arr[1000];
arr[0] = 1;arr[1] =1;
for(i =2;i<=n;i++){
    arr[i] = arr[i-1] + arr[i-2];
}

//with recursion
/*
static int i = 2; static int arr[1000];
arr[0] = 1;arr[1] =1;
arr[i] = arr[i-1] + arr[i-2];
i++;
fibo(i);
*/
for(i = 0;i<=n;i++)
printf("%d   ",arr[i]);


}
