#include <stdio.h>
#include <stdlib.h>
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while(start < end)
    {

        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }


}
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);

  printf("\n");
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    printArray(arr, 7);
    rvereseArray(arr,0,6);
    printf("Reversed array is \n");
    printArray(arr,7);
    return 0;
}
