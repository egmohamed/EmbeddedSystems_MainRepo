#include <stdio.h>
#include <stdlib.h>
int sum(int *arr1, int size){
    int summ =0; int i;
for(i = 0;i<size;i++)
    summ = *(arr1+i)+summ;
return summ;
}
int main()
{
    int size; int i;
    printf("Determin the size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array elements : ");
    for(i = 0;i<size;i++)
    scanf("%d",(arr+i));
    int res = sum(arr,size);
    printf("Sum result = %d",res);
    return 0;
}
