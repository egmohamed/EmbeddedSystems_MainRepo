#include <stdio.h>
#include <stdlib.h>
#define con(c) (c * (float)9/5 +32)
int main()
{
    //with int and float

 int c ; float f;
printf("enter degree in celisius ");
scanf("%d",&c);
f =  c * (float)9/5 +32;
printf ("your degree in fehrenhit : %f",f);

    //with while loop
/*
 int c ; float f;
while(1){
        printf("enter degree in celisius ");
   scanf("%d",&c);
    f =  c * (float)9/5 +32;
    printf ("your degree in fehrenhit : %f \n",f);
}
*/
    //with macros
/*
int c ; float f; float res;
printf("enter degree in celisius ");
scanf("%d",&c);
res = con(c);
printf ("your degree in fehrenhit : %f",res);
*/
    return 0;
}
