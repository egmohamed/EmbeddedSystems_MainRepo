#include<stdio.h>

#define SIZE      6
#define BOOLSIZE  101

void FindMissingNum(int *Arr);


void FindMissingNum(int *Arr)
{
    static int boolArr[BOOLSIZE];
    int firstZero = -1, firstNonZero = -1;
    int i;

    for(i = 0; i < SIZE; i++)
    {
        if(Arr[i] >= 0 && Arr[i] <= 99)
        {
            boolArr[Arr[i]] = 1;
        }

    }

    boolArr[100] = 1;

    for(i = 0; i < BOOLSIZE; i++)
    {
        if(boolArr[i] == 0)
        {
            if(firstZero == -1)
            {
                firstZero = i;
            }

        }

        else
        {
            if(firstZero != -1)
            {
                 firstNonZero = i;
                 printf("%d>%d , ", firstZero, firstNonZero -1);
                 firstZero = -1;
            }
        }
    }

}

int main()
{
int arr[SIZE] = {9,33,66,8,9,0};
FindMissingNum(arr);
return 0;
}
