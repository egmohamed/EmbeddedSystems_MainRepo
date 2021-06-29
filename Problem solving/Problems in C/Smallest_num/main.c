#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    printf("Enter 3 numbers to check the smallest : \n");
    scanf("%d",&a);
    scanf(" %d",&b);
    scanf(" %d",&c);
    if(a<=b && a<=c)
        printf("first number is the smallest or equal one of the other two numbers at least ");
    else if(b<=a&&b<=c)
         printf("second number is the smallest or equal one of the other two numbers at least ");
    else
         printf("third number is the smallest or equal one of the other two numbers at least ");
    return 0;
}
