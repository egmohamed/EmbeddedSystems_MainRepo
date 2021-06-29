#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
int main()

{

 char str[30];
 printf("Enter numbers or string to get them permutations : ");
 scanf("%s",str);

 int n = strlen(str);

 permute(str, 0, n-1);

 return 0;

}
