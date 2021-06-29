#include <stdio.h>
#include <stdlib.h>

int add(int *num1,int *num2){
    return *num1+*num2;
    }
int main()
{
    int x; int y;
    printf("Enter the first number : ");
    scanf("%d",&x);
    printf("Enter the second number : ");
    scanf("%d",&y);
    int res = add(&x,&y);
    printf("Result = %d",res);
    return 0;
}
