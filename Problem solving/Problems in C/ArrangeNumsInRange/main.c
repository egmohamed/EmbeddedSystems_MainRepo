#include <stdio.h>
#include <stdlib.h>

unsigned char* arr(unsigned char u,unsigned char l)
{
    unsigned char i = 0;
    static unsigned char crArr[256];
    if(l>=u)
    {
        crArr[0] = 255; crArr[1] = 255;
        return crArr;
    }
    else
    {
        while(u>=l)
        {
            u--;
            if(l == u)
             {
                  break;
             }
             crArr[i] = u;
             i++;
        }
return crArr;
    }

}
int main(void)
{
    unsigned char i;
    unsigned char* myarr;
    myarr = arr(255,0);
    for(i = 0;i<255;i++)
    {
         printf("\n%d",myarr[i]);
    }

}
