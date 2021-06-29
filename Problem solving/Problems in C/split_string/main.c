#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[30];   char ch;    int i=0;
    printf("Enter string to split it's words : ");
    while(ch != '\n'){
        ch = getchar();
        arr[i] = ch;
        if(isspace(ch)){
            arr[i]= '\n';
        }
        i++;
    }
    for(i = 0;i<11;i++)
        printf("%c",arr[i]);

    return 0;
}
