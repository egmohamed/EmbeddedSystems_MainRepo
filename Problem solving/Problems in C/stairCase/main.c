#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void staircase(int n) {
int i; int j; int ind = n; int ind2 = 0;
    for(i = 0;i<n;i++){
        ind--; ind2++;
        for(j = 0; j<ind; j++)
            printf(" ");

        for(j = 0;j<ind2;j++)
            printf("#");

        printf("\n");
    }

}

int main()
{
    long long x;
  //staircase(50);
  printf("%d",sizeof(x));
   return 0;
}
