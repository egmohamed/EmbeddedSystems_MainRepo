#include<stdio.h>
#include<stdlib.h>
#include"header.h"
int main(){
    int n; int k;
    printf("Enter the size of array : ");
    scanf("%d",&n);
int arr[n];
printf("Enter the array elements : \n");
for(k =0;k<n;k++)
    scanf(" %d",&arr[k]);
int *sorted_array = sort(arr,n);
printf("Sorted array is : ");
for(k = 0;k<n; k++)
    printf(" %d  ",*(sorted_array + k));
}
