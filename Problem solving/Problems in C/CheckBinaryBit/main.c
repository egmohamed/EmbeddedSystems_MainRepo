#include <stdio.h>
#include <stdlib.h>

char checkbit(long num,char bit)
{
    if((num & (1<<bit))>>bit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(void)
{
   char res = checkbit(77,3);
   printf("%d",res);
}
