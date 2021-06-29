
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw(int number)
{

    int i = 0,j = 0,k = 0,space1 = 0,space2 = 0;
    for(i = 0;i<number;i++)
    {
        if(i == 0){printf("*");}
        for(j = 0;j<space1;j++)
        {
            printf(" ");
        }
       if(i != 0){ printf("*");}
        for(k = i;k< (((2*number) -3) - space2) ;k++)
        {
            printf(" ");

        }
        if(i != number -1)
        {
             printf("*");
        }

        printf("\n");

        space1++;
        space2++;

    }
}

int main()
{
    draw(5);
}

