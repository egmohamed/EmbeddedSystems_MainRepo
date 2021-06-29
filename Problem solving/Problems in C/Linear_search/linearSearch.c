#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int linearSearch(char* arr,int len,char target){
int i;
for(i = 0;i<len;i++){
    if(arr[i] == target)
        return i;
}
}
