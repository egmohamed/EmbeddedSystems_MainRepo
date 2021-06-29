#include <stdio.h>
#include <stdlib.h>

int main()
{
     int i; int size; int start;
   printf("Enter the size of array : ");
   scanf("%d",&size);
   int arr[size];
   printf("Enter the array elements : \n");
   for(i = 0;i<size;i++)
    scanf(" %d",&arr[i]);
    printf("Enter the index of start search : ");
    scanf("%d",&start);
    int val = FindMin(arr,size,start);
    printf("Min index = %d ",val);

}
