#include <stdio.h>
#include <stdlib.h>

int main()
{
    int per;
    printf("Enter the percentage of student : ");
    scanf("%d",&per);
    if (per >=85)
        printf("Excellent ");
    else if(per>=75)
        printf("Very good ");
    else if (per>=65)
        printf("Good ");
    else if (per>=50)
        printf("Pass ");
    else
        printf("Fail ");
    return 0;
}
