#include <stdio.h>
#include <stdbool.h>
char arr2[50];
char func(unsigned short x,unsigned char* arr)
{
     char i;
     char y = 0;
     unsigned char max = 0;
   for(i = 0;i<14;i++)
   {

       if(x == arr[i])
       {
          y++;

       }

       else
       {
           y = 0;
       }
    arr2[i] = y;
   }
for(i = 0;i<50;i++)
{

    if(arr2[i] > arr2[max])
    {
        max = i;
    }
    else
    {

    }

}
return arr2[max];
}

int main()
{

  unsigned char arr[] = {1,2,2,3,3,3,3,4,4,4,4,3,3,3};
  char res = func(4,arr);
  printf("%d",res);
    return 0;
}
