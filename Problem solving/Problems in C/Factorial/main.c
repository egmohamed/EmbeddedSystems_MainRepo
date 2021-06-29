#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,count,res;
    printf("Enter number to calculate it's factorial : ");
    scanf("%d",&num);
    res = num;
    for(count = 2;count<res;count++){
        num = num*count;
    }
   printf("Factorial = %d",num);
    return 0;
}
