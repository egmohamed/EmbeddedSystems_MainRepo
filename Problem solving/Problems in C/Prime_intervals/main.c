#include <stdio.h>
#include <stdlib.h>
#include "prime.h"
int main()
{
int int1; int int2;
printf("Enter two numbers to determine the interval : ");
scanf(" %d %d",&int1,&int2);
prime_int(int1,int2);
    return 0;
}
