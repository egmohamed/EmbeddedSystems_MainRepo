#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i; int size;
   printf("Enter the size of array : ");
   scanf("%d",&size);
   int arr[size];
   printf("Enter the array elements : \n");
   for(i = 0;i<size;i++)
    scanf(" %d",&arr[i]);
    int *sorted_arr = bubbleSort(arr,size);
    printf("Sorted array = ");
    for(i =0;i<size;i++)
        printf("%d  ",sorted_arr[i]);

    return 0;
}
