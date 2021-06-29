#include <stdio.h>
char flag;
char checkPower(unsigned short x)
{
    unsigned short temp = 0;
    flag++;
    while(x != 1)
    {
        flag++;
        if((x %2) != 0)
        {
            return 1;
        }
        else
        {
            x /= 2;;
        }

    }
    if(flag == 1 && x == 1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    char res = checkPower(1024);
    printf("%d",res);
    return 0;
}
