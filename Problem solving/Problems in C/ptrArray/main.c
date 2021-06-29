#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size =0;
    char ch;
    printf("Determine the size of array : ");
    scanf("%d",&size);
    printf("Chose to enter char array or array of numbers : n/c ? ");
    scanf(" %c",&ch);
    if(ch == 'c'){
        char arrc[size];
        char *ptrc = arrc;
        printf("Enter the elements of array : ");
        int i;
        for(i = 0; i<size;i++)
        scanf(" %c",(ptrc+i));
        printf("You entered : ");
        for(i = 0; i<size;i++)
        printf("%c  ",*(ptrc+i));
    }
    else
    if(ch =='n'){
        int arra[size];
        int *ptra = arra;
        printf("Enter the elements of array : ");
        int j;
        for(j = 0; j<size;j++)
        scanf("%d",(ptra+j));
        printf("You entered : ");
        for(j = 0; j<size;j++)
        printf("%d  ",*(ptra+j));

    }
    return 0;
}
