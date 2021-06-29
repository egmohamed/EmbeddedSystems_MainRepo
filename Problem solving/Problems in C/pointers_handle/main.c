#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int *ptr2;
    ptr2 = ptr;
    int x =5; int y =6;
    ptr  = &x;
    printf("%p\t %p\n",ptr,ptr2);
     printf("%d\t %d\n",y,*(ptr)+1);
     printf("%d",*(ptr+2));

  //  printf("%d",*ptr);
    return 0;
}
