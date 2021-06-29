#include <stdio.h>
#include <stdlib.h>
int *func(int *x){
*(x) = *(x)+1;
return x;
}
int main()
{
    int num;
    scanf(" %d",&num);
    int *ret = func(&num);
    printf("%d",*ret);
    return 0;
}
