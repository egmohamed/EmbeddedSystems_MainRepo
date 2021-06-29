#include <stdio.h>

#define UniqueArrSize	3
int UniqueNum(int* arr);

int main()
{
	int i;
	
	int arr[UniqueArrSize] = {4,2,4};
	printf("Unique number in the array: ");
	for(i = 0; i < UniqueArrSize; i++)
		printf("%d ", arr[i]);
	
	
	int res = UniqueNum(arr);
	printf("= %d", res);

}

int UniqueNum(int* arr)
{
	int i; int ret = 0;
	
	for(i = 0; i < UniqueArrSize; i++)
	{
		ret ^= arr[i];
	}
	
	return ret;
}