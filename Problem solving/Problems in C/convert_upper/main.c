#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convertUpper.h"
int main()
{
    printf("Enter string in upper case to convert it : ");
     char arr[100];
    scanf("%s", arr);
    int len = strlen(arr);
    char* strUpper = str_upper(arr,len);
    printf("%s",strUpper);
    return 0;
}
