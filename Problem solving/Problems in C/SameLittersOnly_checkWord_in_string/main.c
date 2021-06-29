
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int draw(char* sent, char* word)
{
    int i = 0;  int j; int count = 0; int temp; int k = 0; int wordnum = 0; int count2 = 0;
while(sent[k] != '\0')
{

while(sent[i] != ' ' && sent[i] != '\0')
{

    for(j = 0; j<strlen(word);j++)
    {
        if(word[j] == sent[i])
        {
            count++;

        }
        if((count - count2)  >1)
        {
            count--;
        }

    }
    count2 = count;
    i++;
}
wordnum++;
if(count2 == strlen(word))
    {
        return wordnum;
    }
    else
    {
        i++;
        count = 0;

    }
k = i;
}
return -1;
}

int main()
{

printf("%d",draw("hellloo world man","heololl"));
}

