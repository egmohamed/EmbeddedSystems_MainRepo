#include<stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <time.h>
int longestConsecutive(int *arr);
int* countDecendingInbetweenBounds(int lower, int upper, int* arrSize);
int findMaxZerosInBinary(unsigned int num);
int findMinValueInLinkedList(void);

#define SIZE 20


void strReverse (char* str)
{
	if(*str == '\0')
		return;

	strReverse(str + 1);
	printf("%c", *str);
}
int main(void)
{
    
}

void swap(int x)
{

}

#if 0

#include <stdio.h>
#define ArrSize 10

int FindLastOccur(int* arr, int n);

int main()
{
    int arr[] = {1,2,3,4,4,5,6,7,3,6};
    int ret = FindLastOccur(arr,4);
    printf("%d", ret);
    return 0;
}

int FindLastOccur(int* arr, int n)
{
    int i;

    for(i = ArrSize -1; i >= 0; i--)
    {
        if(arr[i] == n)
            return i;
    }

     return -1;
}

#include <stdio.h>

#define GreaterSize 6
#define SmallerSize 6

void SwapArr(int* arr1, int* arr2);

int main()
{
int i;
int arr1[SmallerSize] = {4,5,6,9,9,9};
int arr2[GreaterSize] = {0,9,8,1,2,3};

SwapArr(arr1, arr2);

for(i = 0; i <GreaterSize; i++)
    printf("%d ", arr2[i]);
}

void SwapArr(int* arr1, int* arr2)
{
    int i, temp = 0;

    for(i = 0; i < SmallerSize; i++)
    {
        temp = arr2[i];
        arr2[i] = arr1[i];
        arr1[i] = temp;
    }
}


#include <stdio.h>
#define ArrSize 6

void ReverseArr(int*);

int main()
{
int i;
int arr[6] = {4,5,6,9,9,9};


ReverseArr(arr);

for(i = 0; i <ArrSize; i++)
    printf("%d ", arr[i]);

}

void ReverseArr(int* inArr)
{
    int i, j, temp = 0;

    for(i = 0, j = ArrSize -1; i <= j; i++, j--)
    {
        temp = inArr[i];
        inArr[i] = inArr[j];
        inArr[j] = temp;

    }
}

#include <stdio.h>
#define ArrSize 4

unsigned int AsciiToDecimal(char* arr);

int main()
{
    char arr[ArrSize] = {'8', '2', '7', '1'};
    unsigned int ret = AsciiToDecimal(arr);
    printf("%d", ret);
    return 0;
}

unsigned int AsciiToDecimal(char* arr)
{
    int i; int num = 0; int k = 1;

    for(i = ArrSize -1; i >= 0; i--)
    {
        num += (arr[i] - 0x30) * k;
        k *= 10;
    }
    return num;
}

#include <stdio.h>
#include <math.h>

int ClearBit(int num, int pos);

int main()
{
    int ret;
    ret = ClearBit(0b01111,5);
    printf("%d", ret);
}

int ClearBit(int num, int pos)
{
    /* To check if the input pos is a valid input i.e in the binary range of the num, we
     * calculate the minimal number the pos can reach to (2^pos) and check if the num input
     * is greater than this value then we are confident that the pos is within the range
     */
    if((pow(2,(double)pos)) > (double)num)
        return num;
    else
        return num & (~(1<<pos));
}

#include <stdio.h>

int forthLeastBit(int num);

int main()
{
    int ret = forthLeastBit(8);
    printf("%d",ret );
    return 0;
}

int forthLeastBit(int num)
{
    return  (( (1 << 3) & num ) >> 3);
}

#include <stdio.h>

int IsPower3(int n);

int main()
{
    int ret = IsPower3(9);
    printf("%d", ret);
    return 0;
}

int IsPower3(int n)
{
    /* Note that 1162261467 is the biggest power of 3 number (3^19) can fit in int size.
     * if the reminder of this number divided by the input number is zero then the
     * input number is power of three. This solution is customized for int type if you want
     * to use uint32 then the biggest number will be (3^20). the advantage of this method is
     * that it takes O(1) in time and space complexity independently from any language library
     */
    return !(n > 0 && n > 1 && 1162261467 % n == 0);
}

#include <stdio.h>
#include <string.h>

int CheckUserName(void);

int main()
{
    int ret;
    ret = CheckUserName();
    ret? printf("the user name input is NOT correct") : printf("the user name input is correct");
}

int CheckUserName(void)
{
    char* success = NULL;
    char arr[100]; const char UserName[] = "USERNAME\n";
    success = fgets(arr, 100, stdin);

    if(success)
        return strcmp(arr, UserName);
    return - 1;
}
int longestConsecutive(int *arr)
{
    int i = 0, count = 1, max = INT_MIN;

    for(i = 0; i < SIZE - 1; i++)
    {
        if(max < count)
        {
           max = count;
        }

        if(arr[i+1] != arr[i])
        {
            count = 1;
        }
        else
        {
            count++;
        }
    }

    return max;
    */


int* countDecendingInbetweenBounds(int lower, int upper, int* arrSize)
{
    int i; int count = 0;

    if(lower >= upper)
    {
        *arrSize = 2;
        static int arr[2] = {0xFF, 0xFF};
        return arr;
    }

    static int arr2[256];
    int j = 0;

    for(i = upper -1; i > lower; i--)
    {
        arr2[j] = i;
        j++;
        count++;
    }


    *arrSize = count;
    return arr2;

}


int findMaxZerosInBinary(unsigned int num)
{
    int zeroCount = 0, flag = 0, max = INT_MIN;

    while(num)
    {
       if( (num & 1) == 1)
       {
           flag = 1;
       }

       if(flag == 1)
       {
           //Important note: be aware that "==" has a higher precedence that "&"
           //and if you ignored the parenthesis then 1 will be compared to zero then bitwise and will take place
           //and this is unwanted behavior
           if( (num & 1) == 0)
           {
               zeroCount++;
           }
           else
           {
               if(max < zeroCount)
               {
                   max = zeroCount;
               }

               zeroCount = 0;
           }
       }
        num = num>>1;
    }
}


int findMinValueInLinkedList(void)
{
    int *ptr; int min = INT_MAX;


    while(ptr != NULL)
    {
        if(min > ptr->data)
        {
            min = ptr->data;
        }

        ptr = ptr->next;

    }
}
#endif // 0
