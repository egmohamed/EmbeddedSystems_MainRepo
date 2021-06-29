#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    printf("Enter two numbers to find the max between them : ");
    scanf("%d",&num1);
    scanf("%d",&num2);
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    if(*ptr1>*ptr2)
        printf("first number is the maximum number ");
    else
        printf("Second number is the maximum number ");
    return 0;
}
