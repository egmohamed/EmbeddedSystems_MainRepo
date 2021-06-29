#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num; int res = 1;
    for(num =2 ;num<=100;num++){

        res = res+num;

    }
    printf("sum of 100 = %d",res);
    return 0;
}
