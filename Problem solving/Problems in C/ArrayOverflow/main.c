
#include <stdio.h>
#include <string.h>
void fun(void)
{
    static unsigned char arr[256] = {0};
    int i;
    for(i = 0;i<256;i++)
    {
        while(1)
        {
            printf("%d\n",arr[i]);
            arr[i] += 1;
            if(!arr[i])
            {
                arr[i+1] += 1;
                printf("\t%d\n",arr[i+1]);
                if(arr[i+1] == 0)
                {
                    arr[i+2]+= 1;
                    break;
                }
            }
        }
    }
    return arr;
}

int main()
{
fun();

}


