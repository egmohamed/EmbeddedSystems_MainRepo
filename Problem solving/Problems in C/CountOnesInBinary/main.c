#include <stdio.h>
#include <stdlib.h>

unsigned int countOnes(unsigned int num)
{
    unsigned int count = 0;

   while(num != 0)
   {

       if(num%2 == 1)
       {
           count++;
       }
       num = num/2;
   }
   return count;


}
int main(void)
{
    unsigned int num2;
    num2 = countOnes(32);
    printf("%d",num2);

}
