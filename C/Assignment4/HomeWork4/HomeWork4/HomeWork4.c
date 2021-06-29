#include "HomeWork4.h"

// since we don't use dynamic allocation in this problem solution,
// please put the ArrSizeEx1 to the maximum size of the prime numbers
// you want to show otherwise array elements will exceed the boundaries
// and the program may crash

#define ArrSizeEx1  100

void PrimeNumInterval(void)
{
    int num1, num2; int i,j, k = 0;
    int arr[ArrSizeEx1]; int NotPrime = 0; int count =0;
    printf("Enter two numbers(intervals): ");
    scanf("%d %d", &num1, &num2);

    for(i = num1; i <= num2; i++)
    {
        NotPrime = 0;
        for(j = 2; j <= i/2; j++)
        {
            if(i % j == 0)
            {
                NotPrime = 1;
                break;
            }
        }
        if(!NotPrime)
        {
           if(!(num1 >= 0 && (i == 2 || i == 1 || i == 0)))
           {
             arr[k] = i;
             count++;
             k++;
           }
        }

    }

    printf("Prime numbers between %d and %d are: ", num1, num2);
    for(i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

}

int RecursionFac(int num)
{
    if(num == 1 || num == 0)
    {
        return 1;
    }

    return num*RecursionFac(num-1);
}

char RecursionRevStr(char* arr)
{
    if(arr[0] == '\0')
        return '\0';

    RecursionRevStr(arr+1);
    return printf("%c", arr[0]);

}

int RecursionNumPow(int num, int pow)
{
    if(pow == 1)
        return num;

    return num*RecursionNumPow(num, pow-1);
}
