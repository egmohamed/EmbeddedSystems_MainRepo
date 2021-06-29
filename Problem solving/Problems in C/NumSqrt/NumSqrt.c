#include <stdio.h>

double NumSqrt(int num);

int main()
{
	int num1 = 4;
	double res = NumSqrt(num1);
	printf("square root of %d = %lf", num1, res);
	
	num1 = 10;
	res = NumSqrt(num1);
	printf("\nsquare root of %d = %lf", num1, res);
}

double NumSqrt(int num)
{
    double error = 0.0000001;
    double rec = num;

    while ((rec - (num / rec)) > error) 
    {
        rec = (rec + (num / rec)) / 2;
    }

    return rec;

}
