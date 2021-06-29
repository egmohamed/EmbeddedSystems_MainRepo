#include <stdio.h>
#include <stdlib.h>

int main()
{
   int first,second;
   printf("Enter the first number ");
   scanf("%d",&first);
    printf("Enter the second number ");
   scanf(" %d",&second);
   if(first%second==0)
    printf("first number is multiple of the second ");
   else
    printf("first number is NOT multiple of the second ");
    return 0;
}
