#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int boxes; int i;
   printf("Enter number of boxes : ");
   scanf("%d",&boxes);
   int hight[boxes];
   int width[boxes];
   int length[boxes];
   printf("Enter Dimentions of boxes : \n");
   printf("Enter the hight of arrays : ");
   for(i = 0;i<boxes;i++)
   scanf(" %d",(hight+i));
   printf("Enter the width of arrays : ");
   for(i = 0;i<boxes;i++)
   scanf(" %d",(width+i));
   printf("Enter the length of arrays : ");
   for(i = 0;i<boxes;i++)
   scanf(" %d",(length+i));
    passed(boxes,hight,width,length);

    return 0;
}
