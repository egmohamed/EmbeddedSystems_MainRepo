
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* str_upper(char arr[],int len){
int i; int j;
for(i = 0;i<len;i++){
    for(j = 65;j<90;j++){
        if(arr[i] == j)
            arr[i] = j+32;
    }
}
return arr;
}
