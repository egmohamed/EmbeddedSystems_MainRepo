#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void ifRepeated(char* strn, int len){
    int i; int j; char temp;
for(i = 0;i<= len;i++){
   for(j = i+1;j<len;j++){
    if(strn[i] == strn[j]){
        printf("FALSE");
    return;
    }
    else
        {
        }
        }
   }
   printf("TRUE");
}

