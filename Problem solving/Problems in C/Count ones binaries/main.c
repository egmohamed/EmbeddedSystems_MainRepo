#include <stdio.h>
#include <stdlib.h>

unsigned char countones(unsigned long x)
{
    unsigned short num,count,count2;
    count = 0; count2 = 0;
    while(x != 0)
    {
        count2++;
        num = x%2;
        if(num == 1)
        {
            count++;

        }

        printf("%d",num);
        x/=2;
    }
    return count;
}
int main()
{
   unsigned char res = countones(4);
   printf("\n%d",res);
    return 0;
}
