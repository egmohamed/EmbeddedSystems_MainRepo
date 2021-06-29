#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Enter to check if the number is a perfect square : ");
    double num,res;
    scanf("%lf",&num);
    if((pow(num,.5)-(((int)(pow(num,.5))/1)*1) == 0)){
       printf("number is a perfect square ");
    }
    else
       printf("number is NOT perfect square ");
    return 0;
}
