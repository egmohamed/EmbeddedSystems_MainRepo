#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter string to count vowels and consonants : ");
   char arr[5];
   int count;
   char *ptr = arr;
   char ch;
   int i;
   while(ch != '\n'){
    ch = getchar();
    *(ptr+i) = ch;
    if(ch == 'a'|| ch == 'e'|| ch =='i'|| ch=='o'|| ch =='u'||ch == 'A'|| ch == 'E'|| ch =='I'|| ch=='O'|| ch =='U')
        count++;
    i++;
   }
   printf("%d",count-75); //el 75 far2 da geh mnen
    return 0;
}
