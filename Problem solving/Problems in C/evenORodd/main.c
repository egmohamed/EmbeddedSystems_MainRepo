#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please enter number to check : \n");
    int num;
    scanf("%d",&num);
    if (num%2==0)
        printf("number is even ");
    else
        printf("number is odd ");
    return 0;
}
