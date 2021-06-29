#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ch;
    char arr[1];
    printf("Entet array elements : ");


 char *ptr = arr;
    char *ptr2;  int i =0;
    while(ch != '\n'){
        ch = getchar();
        *(ptr+i) = ch;
         i++;
        ptr2 = ptr+i;

    }

    printf("%d",(ptr2-ptr));

    return 0;
}
