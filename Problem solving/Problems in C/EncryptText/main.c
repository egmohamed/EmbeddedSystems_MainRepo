#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* EncryptText(char* str, int l);

int main () {

char Str[] = "this is an introduction to embedded systems";
int L = sizeof(Str) - 1;
char* res = EncryptText(Str, L);

return(0);

}

char* EncryptText(char str[], int l)
{
    int i; char str2[l];
    int j = 0;
    for(i = 0; str[i] != 0 ; i++, j++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {

            str2[j] = str[i];
        }
        else
        {
            j--;

        }

    }
    str2[j] = '\0';
    //printf("%d\n", j);
    float sq = sqrt(j);
    int lower = floor(sq);
    int higher = ceil(sq);
    int mul = lower*higher;

    if(j > mul)
    {
        lower++;
    }

    char Letters[lower][higher];
    int k = 0;
    for(i = 0; i< lower; i++)
    {
        for(j = 0; j < higher; j++)
        {
            Letters[i][j] = str2[k];
            k++;

        }
    }

     for(i = 0; i < higher; i++)
     {
         for(j = 0; j < lower; j++)
         {
            if(Letters[j][i] < 'a' || Letters[j][i] > 'z')
            {
                continue;
            }
             printf("%c", Letters[j][i]);
         }

         printf(" ");
     }


}
