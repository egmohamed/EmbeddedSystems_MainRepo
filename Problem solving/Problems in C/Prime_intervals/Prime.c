#include <stdio.h>
#include <stdlib.h>

void prime_int(int int1,int int2){
    int i;
    for(i =int1;i<int2;i++){
        if(i%2 != 0 && i%3 != 0 && i%5 !=0 && i%7 !=0 &&i%11 !=0)
            printf("%d \t",i);
        else{}
    }

}
