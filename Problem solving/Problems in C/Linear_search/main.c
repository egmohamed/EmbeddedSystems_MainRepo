#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char arr[40];
    int len; char target;
    printf("Enter the array elements as string input : ");
    scanf("%s",arr);
    len = strlen(arr);
    printf("Enter the element you want to search for : ");
    scanf(" %c", &target);
    int ind = linearSearch(arr,len,target);
    printf("%d",ind);
    return 0;
}
