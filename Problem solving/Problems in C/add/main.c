#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *ptr1;
   int *ptr2;
   int x; int y;
   printf("Enter first number : ");
   scanf("%d",&x);
   printf("Enter the second number : ");
   scanf(" %d",&y);
   ptr1 = &x;
   ptr2=&y;
   printf("Result = %d",*(ptr1) + *(ptr2));
    return 0;
}
