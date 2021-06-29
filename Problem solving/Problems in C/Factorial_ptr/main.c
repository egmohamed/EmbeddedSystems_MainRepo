#include <stdio.h>
#include <stdlib.h>
int *factorial(int *num){
int count,res;
    res = *(num);
    for(count = 2;count<res;count++)
        *(num) = *(num)*count;
return num;
}
int main()
{
    int num1;
 printf("Enter number to calculate it's factorial : ");
   scanf("%d",&num1);
    int *x = factorial(&num1);
   printf("Factorial = %d",*x);
    return 0;
}
