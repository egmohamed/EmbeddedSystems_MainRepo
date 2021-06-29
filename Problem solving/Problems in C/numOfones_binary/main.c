#include <stdlib.h>
#include <stdio.h>
int numofOnes(int num){
    int num2; int count = 0;
while(num != 0){
    num2 = num;
   num2 = num2%2;
   if(num2 == 1){count++;}
   num = num/2;

}
return count;
}

int main(void){
 int res = numofOnes(64);
 printf("%d",res);
}
