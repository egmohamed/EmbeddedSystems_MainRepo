#include <stdio.h>

void SoliderAndBanana(unsigned int k, unsigned int n, unsigned int w)
{
    int i; unsigned int sum = 0;
    unsigned int res = 0;
    for(i = 1; i<= w; i++ )
    {
        sum += k*i;
    }
    
    if(sum > n)
    {
        res = sum - n;
        printf("%d\n", res);
    }
    else 
    {
        printf("0\n");
    }
   
}

int main (void)
{
    unsigned int K, N, W;
    scanf("%d ", &K);
    scanf("%d ", &N);
    scanf("%d ", &W);
    
    SoliderAndBanana(K, N, W);
}