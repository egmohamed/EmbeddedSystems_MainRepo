#include <stdio.h>
#include <stdlib.h>
int get_factors(int size1, int size2, int* arr1, int* arr2)
{
    int max1 = 0, min1 = 101; int i; int j;
    int max2 = 0, min2 = 101; int minimest, maximest;
    for(i =0; i< size1; i++)
    {
        if(max1 < arr1[i])
        {
            max1 = arr1[i];
        }
        if(min1 > arr1[i])
        {
            min1 = arr1[i];
        }
    }
    for(i =0; i< size2; i++)
    {
        if(max2 < arr2[i])
        {
            max2 = arr2[i];
        }
        if(min2 > arr2[i])
        {
            min2 = arr2[i];
        }
    }
    minimest = min1 < min2 ? min1: min2;
    maximest = max1 > max2 ? max1: max2;
    int flag1 = -1; int count = 0; int flag2 = -1;
    for(i = minimest; i<= maximest; i++)
    {
        flag1 = -1; flag2 = -1;
        for(j = 0; j<size1; j++)
        {
            if(i%arr1[j] != 0)
            {
                flag1 = 1;
                break;
            }
        }
        for(j = 0; j<size2; j++)
        {
            if(arr2[j]%i != 0)
            {
                flag1 = 1;
                break;
            }
        }
        if(flag1 == -1)
        {
            count++;
            continue;
        }
        for(j = 0; j<size2; j++)
        {
            if(i%arr2[j] != 0)
            {
                flag2 = 1;
                break;
            }
        }
        for(j = 0; j<size1; j++)
        {
            if(arr1[j]%i != 0)
            {
                flag2 = 1;
                break;
            }
        }
        if(flag2 == -1)
        {
            count++;
            continue;
        }


    }
    return count;
}
int main()
{
    int arr1[2] = {2,4}; int arr2[3] = {16,32,96};
    printf("%d",get_factors(2,3,arr1,arr2));
    return 0;
}
