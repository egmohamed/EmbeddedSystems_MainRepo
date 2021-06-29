#include <stdio.h>
#include <stdlib.h>

unsigned char* ReverseLetters(char* word)
{
    static unsigned char revword[2];
    unsigned char temp;
    int i;
   for(i = 0;i<100;i++)
   {
       if(word[i] == '\0')
       {
          revword[0] = word[i-2];
          revword[1] = word[i-3];
          return revword;

       }
   }


}
int main(void)
{
unsigned char* arr;
char entername[5] = "Apple";
arr = ReverseLetters(entername);
int i;
for(i = 0;i<2;i++)
{
    printf("%c",arr[i]);
}

}
