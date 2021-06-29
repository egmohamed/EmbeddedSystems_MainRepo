#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char pass[] = "hello";
char check[30];
int i; int k = 1;

while(k ==1){

printf("\nEnter password : ");
scanf("%s",check);
for(i =0;i<strlen(check);i++){
    if(*(pass+i) != *(check+i))
       k =0;


}
if (k == 1){
    printf("pass is correct");
    k = 0;
}
else{
    printf("try again !");
    k =1;
}
}
return 0;

}
//reverse world


