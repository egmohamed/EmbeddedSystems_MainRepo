#include <stdio.h>
#include <stdlib.h>
unsigned int* PowerTwoCheck(unsigned int* Arr)
{
    int i,k;k = 0;
    static unsigned int Arr2[5];
    for(i = 0; i< 5;i++)
    {
        while(Arr[i] != 0)
        {
            if(Arr[i]%2 == 0)
            {
                Arr2[i] = 0;
                break;
            }
            else
            {
                Arr2[i] = 1;
            }

        Arr[i]= Arr[i]/2;

        }

    }
    return Arr2;
}
int main()
{
    int i;
    unsigned int EntryArray[5] = {1,2,4,9,8};
    unsigned int* Results;
    Results = PowerTwoCheck(EntryArray);
    for(i = 0;i<5;i++)
    {
        printf("%d",Results[i]);
    }

    return 0;
}
