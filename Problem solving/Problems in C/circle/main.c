#include <stdio.h>
#include <stdlib.h>
#define pi 3.14
int main()
{
    float r; double area,cir;
    printf("Enter the radius of circle : ");
    scanf("%f",&r);
    area = pi*r*r;
    cir = 2*pi*r;
    printf("area of the circle = %f\n",area);
    printf("circumference of the circle = %f",cir);

    return 0;
}
