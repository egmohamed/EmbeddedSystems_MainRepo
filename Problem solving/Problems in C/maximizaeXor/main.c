#include <stdio.h>

short maxim(int a, int b)
{
     short arr[((b)-(a))*((b) - (a))];
    int i = 0; int j= 0; int max = 0;
    char count =0;
    for(i = a;i<= b;i++)
    {
         for(j = a; j<= b; j++)
         {
              arr[count] = i^j;
              count++;
         }


    }

for(i = 0; i<((b)-(a))*((b) - (a));i++)
{

        if(arr[i] > arr[max])
        {
             max = i;
        }



}

return arr[max];
}

int main()
{

short res = maxim(500,1000);
printf("%d",res);
    return 0;
}
