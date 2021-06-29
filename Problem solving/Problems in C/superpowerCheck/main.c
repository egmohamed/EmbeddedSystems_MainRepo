#include <stdio.h>
#include <stdlib.h>
#define RW_FLAG 0x1FFF7800
unsigned char checknum(unsigned short num)
{
    if(num == 2 || num == 5 || num == 7 || num == 11 || num == 3)
    {
        return -1;
    }
    else
    {
        float n2,n3,n5,n7,n11;
        n2 = num; n3 = num; n5 = num; n7 = num ; n11 = num;
        while(n2 != 1 && n2/2 != 0)
        {
            n2 = n2/2.0;

        }
        while(n3 != 1 && n3/3 != 0)
        {
            n3 = n3/3.0;

        }
        while(n5 != 1 && n5/5 != 0)
        {
            n5 = n5/5.0;

        }
        while(n7 != 1 && n7/7 != 0)
        {
            n7 = n7/7.0;

        }
        while(n11 != 1 && n11/11 != 0)
        {
            n11 = n11/11.0;

        }
        if(n2 == 1|| n3 == 1 || n5 == 1|| n7 ==1 || n11 == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main(void)
{
signed char res = checknum(36);
printf("%d",res);
}
