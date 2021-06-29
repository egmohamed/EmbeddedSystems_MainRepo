#include <stdio.h>

// please set this macro to the maximum prime numbers 
// you want to show
#define ArrSizeEx1 100

int* PrimeNumInterval(int num1, int num2);

int count;

int main(void)
{
	int num1 = 1, num2 = 20; int i;
	int* res = PrimeNumInterval(num1, num2);
	printf("Prime numbers between %d and %d are: ", num1, num2);
	
	for(i = 0; i <count; i++)
		printf("%d ", res[i]);
}
int* PrimeNumInterval(int num1, int num2)
{
	
    int i,j, k = 0;
    static int arr[ArrSizeEx1]; int NotPrime = 0;

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
           if(!(num1 >= 0 && (i == 0)))
           {
             arr[k] = i;
             count++;
             k++;
           }
        }

    }

	return arr;

}