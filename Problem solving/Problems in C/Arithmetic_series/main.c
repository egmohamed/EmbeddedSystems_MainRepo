#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the nth number of arithmetic series : ");
    int n ; int i;
    scanf("%d", &n);
    int* arr = ar_series(n);
    for(i = 0;i<100;i++)  // Important : change i to match n of series
    printf("%d   ",*(arr+i));
    return 0;
}
