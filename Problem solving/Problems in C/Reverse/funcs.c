#include <stdio.h>
#include <stdlib.h>
void reverse(char *arr1,int size){
int i ,j;
char arr2[size];
size -= 1;
for(i = 0,j = size; i<=size,j>=0;i++,j--){
    *(arr2+i) = *(arr1+j);
     printf("%c \n",*(arr2+i));

}

}

