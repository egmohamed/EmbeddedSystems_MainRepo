#include <stdio.h>
#include <stdlib.h>
short LastIndexOccurence(short num,short size,short* arr)
{
    short i;
    for(i = size-1; i>=0; i--)
    {
        if(arr[i] == num)
        {
            return i+1;
        }
        else
        {

        }


    }
    return -1;
}
int main()
{
    short arr[14] = {13,2,3,4,5,6,4,4,5,7,2,7,1,2};
    short res = LastIndexOccurence(14,14,arr);
    printf("%d",res);
    return 0;
}
