#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* superReducedString(char* s);

int main(void)
{
    char Str[] = "bbbbbbaaaa";
    char* res = superReducedString(Str);

    printf("%s", res);
}

char* superReducedString(char* s) {

    int len = strlen(s);
    int i;
    char* str = (char*) malloc(len);
    int j;
    for(i = 0, j = 0; s[i] != '\0'; i+=2, j++)
    {

        if(s[i+1] == 0)
        {
            str[j] = s[i];
            j++;
            break;
        }

        if(s[i] == s[i+1])
        {
            j--;
            continue;
        }

        if(s[i] != s[i+1])
        {
            str[j] = s[i];
            j++;
            str[j] = s[i+1];
        }
    }

    str[j] = '\0';

    if(str[0] == 0)
    {
        return "Empty String";
    }

    return str;

}
