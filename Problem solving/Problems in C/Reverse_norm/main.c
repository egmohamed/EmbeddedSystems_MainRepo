#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;   int i,j;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    char arr[size];
    printf("Enter array elements to print them in reverse order : \n");
    for(i = 0;i<size;i++)
        scanf(" %c",&arr[i]);
         printf("Array in reversed order : \n");

char arr2[size];
size -= 1;
for(i = 0,j = size; i<=size,j>=0;i++,j--){
    arr2[i] = arr[j];
     printf("%c \n",arr2[i]);
}
    return 0;
}
