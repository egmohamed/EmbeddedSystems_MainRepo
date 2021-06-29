#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"
int main()
{
    int n;
    printf("Enter the nth number of fibonacci series : ");
    scanf("%d",&n);
    fibo(n);
    return 0;
}
