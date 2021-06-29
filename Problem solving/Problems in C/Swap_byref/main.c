#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *ptr1,char *ptr2){
char temp[30];
int i;
for(i = 0;i<strlen(ptr1);i++){
*(temp+i) = *(ptr2+i);
*(ptr2 +i) = *(ptr1 +i);
*(ptr1 +i) = *(temp +i);
}
printf("first swapped array : ");
for(i = 0;i<strlen(ptr1);i++)
printf("%c ",*(ptr1+i));
printf("\nsecond swapped array : ");
for(i = 0;i<strlen(ptr1);i++)
printf("%c ",*(ptr2+i));
}
int main()
{
    int i;
   char arr1[5];
   char arr2[5];
   printf("Enter first array elements : ");
   for(i = 0;i<5;i++)
   scanf("  %c",arr1+i);
   printf("Enter the second array elements : ");
   for(i = 0;i<5;i++)
   scanf("  %c",arr2+i);
   swap(arr1,arr2);
return 0;
}
//leh btl3 shwayt garbage fe el result
