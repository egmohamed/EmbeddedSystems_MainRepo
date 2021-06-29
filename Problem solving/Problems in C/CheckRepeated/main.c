#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "checkRepeated.h"
#include <string.h>
int main(){

printf("Enter string to check if it's repeated : ");
char arr[100];
scanf("%s", arr);
int len = strlen(arr);
ifRepeated(arr,len);
return 0;
}
