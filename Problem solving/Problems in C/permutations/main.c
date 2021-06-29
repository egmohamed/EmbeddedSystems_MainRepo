#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "headers.h"
/*
int main()
{
    char arr[30]; int i; int j;

    scanf("%s",arr);
    for(i = 0;i<strlen(arr);i++){
        for(j = 0;j<strlen(arr);j++){
            if(arr[i] == arr[j])
                continue;
            swap(arr,i,j);
            printf("%s \n",arr);
        }
    }
  //  printf("%c",arr[5]);
    //printf("Hello world!\n");
    return 0;
}
*/
void swap(char *x, char *y)

{

 char temp;

 temp = *x;

 *x = *y;

 *y = temp;

}
void permute(char *a, int l, int r)

{

 int i;

 if (l == r)

 printf("%s\n", a);
 else

 {

 for (i = l; i <= r; i++)

 {

 swap((a+l), (a+i));

 permute(a, l+1, r);

 swap((a+l), (a+i)); //backtrack

 }

 }

}
int main()

{

 char str[30];
 printf("Enter numbers or string to get them permutations : ");
 scanf("%s",str);

 int n = strlen(str);

 permute(str, 0, n-1);

 return 0;

}
