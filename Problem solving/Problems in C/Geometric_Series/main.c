#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geometric.h"
int main()
{ int n; int i;
   printf("Enter the array nth element of series : ");
   scanf("%d",&n);
   int* res = geometric(n);
   for(i =0;i<=10;i++)  //Important change this up to nth number you want to show
   printf("%d   ",*(res+i));
    return 0;
}
