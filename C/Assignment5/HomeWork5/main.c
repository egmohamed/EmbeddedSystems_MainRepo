#include "HomeWork5.h"

int main()
{
	//DisplayStudentInfo();
	//SumDistance();
	//SumComplexNum();
	//DisplayInfoArr();
	
	//Circle area with macro
	double radius;
	printf("Enter the radius: ");
	scanf("%lf", &radius);
	printf("%lf", CircleArea(radius));
	
	// Last example
	
	/*
	union job
	{
    char name[32];
    float salary;
    int worker_no;
	}u;

	struct job1
	{
    char name[32];
    float salary;
    int worker_no;
	}s;
	*/
	
	//size of union=32
	//size of structure=40
}