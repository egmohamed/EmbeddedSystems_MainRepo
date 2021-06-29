#include <stdio.h>
#include <stdlib.h>

int main()
{

unsigned char x;
printf("Enter character: ");
scanf("%c",&x);
unsigned char counter,counter2;

for(counter = 65, counter2 = 97; counter2 < 123, counter < 91; counter++, counter2++)
{
    if(x == counter || x == counter2)
    {
        printf("character is alphabet\n");
    }
    else
    {

    }
}
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
    {
        printf("character is vowel");
    }
    else
    {
        printf("character is consonant");
    }


    return 0;
}
