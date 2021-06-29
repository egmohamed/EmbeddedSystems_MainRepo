#include <stdio.h>

void SoftDrink(int n, int k, int l, int c, int d, int p, int nl, int np);

void SoftDrink(int n, int k, int l, int c, int d, int p, int nl, int np)
{
    int temp1 = 0, temp2 = 0, temp3 = 0;
    int min;
    temp1 = (k*l)/nl; 
    temp2 = c*d;
    temp3 = p/np;
    
        min = temp1; 
        if(temp2 < min)
        {
            min = temp2;
        }
        
        if(temp3 < min)
        {
            min = temp3;
        }
    
    printf("%d ", min/n);
}

int main(void)
{
    int N, K, L, C, D, P, NL, NP; 
    scanf("%d %d %d %d %d %d %d %d ", &N, &K, &L, &C, &D, &P, &NL, &NP);
    SoftDrink(N, K, L, C, D, P, NL, NP);
    
    return 0;
}