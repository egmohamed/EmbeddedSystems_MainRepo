#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter the number to check if it's prime or not : ");
    scanf("%d",&num);
    if(num%2==0 ||  num%3==0 ||  num%5==0 ||  num%7==0 ||  num%11==0){
       if(num == 2 || num ==3 || num ==5 || num ==7 || num ==11)
        printf("number is prime ");
       else
        printf("number is NOT prime ");
    }
    else
        printf("number is prime ");
    return 0;
}
