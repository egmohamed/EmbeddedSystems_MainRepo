#include <stdio.h>
#include <stdlib.h>

void swap(int num1,int num2){
int temp;
temp = num2;
num2 = num1;
num1 = temp;
printf("%d\t%d",num1,num2);
}
