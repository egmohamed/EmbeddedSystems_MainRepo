#include <stdio.h>
#include <stdlib.h>
unsigned char RisighEdgeCount(unsigned char pin)
{
    unsigned char temp = 0;
    temp = pin;
    static unsigned char count = 0;
    if(temp == 1){
        count++;
    }
    return count;
}
int main(void)
{
    unsigned char res = RisighEdgeCount(1);
    res = RisighEdgeCount(1);
    res = RisighEdgeCount(1);
    res = RisighEdgeCount(0);
    printf("%d",res);

    return 0;
}
