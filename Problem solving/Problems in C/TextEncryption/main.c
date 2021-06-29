#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char* encrypt(char* text){
int i; char arr[81]; int arrlen; int lowcalc = 0 , highcal = 0;
int flag = 0; int m = 0;int count = 0;
int j; int k = 0; static char resArr[81];
for(i = 0; i<=strlen(text); i++)
{

    if((text[i] >= 'a' && text[i] <= 'z') || text[i] == ' ' || text[i] == '\0'){

        if(text[i] != ' ')
        {
          arr[count] = text[i];
          count++;

        }


    }
}
arrlen = strlen(arr);
lowcalc = floor(sqrt(arrlen));
highcal = ceil(sqrt(arrlen));
char encr[9][9];
if(lowcalc * highcal >= arrlen)
{
    for(i = 0; i<lowcalc; i++)
    {
        for(j = 0; j<highcal; j++,k++)
        {
            encr[i][j] = arr[k];
        }
    }
}
else
{
    lowcalc++;
    for(i = 0; i<lowcalc; i++)
    {
        for(j = 0; j<highcal; j++,k++)
        {
            encr[i][j] = arr[k];
        }
    }
}
k = 0;
int i2,j2;
for(i = 0; i<highcal; i++)
    for(j = 0; j<lowcalc; j++,k++)
{
    if(encr[j][i] == '\0')
    {
        i2 = i; j2 = j;
    }
        if(j == j2 && (i >= i2 && i < 7))
        {
            k--;
            continue;
        }




        resArr[k] = encr[j][i];
}
return resArr;
}
int main()
{
    printf("%s",encrypt("this is an introduction to embedded systems"));
    return 0;
}
