#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int repeated(char* arr, char* target)
{
    int i; int targetCount = 0; int j = 0;
    int targetLength = strlen(target); int wordCount = -1;
    int flag = 0; int counter = 0;
    for(i = 0; i< strlen(arr); i++)
    {
        if(arr[i] == ' ')
        {
            targetCount = 0;
            wordCount = 0;
            continue;
        }
        else
        {
            flag = 0;
            for(targetCount = 0;targetCount<targetLength;)
            {
                wordCount++;
                if(arr[i] == target[targetCount])
                {
                     targetCount++;
                     i++;;

                }
                else
                {
                    if(arr[i] == ' ')
                    {
                        targetCount = 0;
                        wordCount = 0;
                        flag = 1;
                        break;
                    }
                    targetCount++;
                    flag = 1;
                    i++;
                }
            }
            if(flag == 0)
            {
                if(wordCount == targetCount)
                {
                    counter++;
                    targetCount = 0;
                    wordCount = 0;
                }
                else
                {
                    targetCount = 0;
                }

            }

        }
    }
    return counter;
}
int main()
{
    char* arrinp = "Welcome to Sprints online exam, Good Luck for everyone in Sprints.";
    char* arrtar = "Sprin";
    printf("%d", repeated(arrinp,arrtar));
    return 0;
}
