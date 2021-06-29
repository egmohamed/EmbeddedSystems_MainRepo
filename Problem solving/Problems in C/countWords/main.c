#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0; int count;
    char ch;
    printf("Enter string to count the words through it : ");
    char str[1000];
    while(ch !='\n'){
        ch = getchar();
        str[i] = ch;
        if(isspace(ch)){
            count++;
        }
            i++;

    }
    printf("number of words = %d",(count-8));

    return 0;
}
