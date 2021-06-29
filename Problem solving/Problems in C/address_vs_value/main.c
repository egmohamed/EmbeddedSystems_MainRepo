#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr;
    int x =6;
    ptr = &x;
    printf("%p\n",ptr);
    printf("%d",*ptr);
    return 0;
}
