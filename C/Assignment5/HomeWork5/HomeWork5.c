#include "HomeWork5.h"

void DisplayStudentInfo(void)
{
	struct student s;
	
	printf("Enter name: ");
	gets(s.Name);
	printf("Enter roll number: ");
	scanf("%d", &s.rollNum);
	printf("Enter marks: ");
	scanf("%f", &s.mark);
	
	printf("Displaying information\n");
	printf("name: %s\n", s.Name);
	printf("Roll: %d\n", s.rollNum);
	printf("Marks: %.3f", s.mark);
}

void SumDistance(void)
{
	struct distance d1, d2;
	int FeetSum; float InchSum;
	
	printf("Enter information for 1st distance: \n");
	printf("Enter feet: ");
	scanf("%d", &d1.feet);
	printf("Enter inch: ");
	scanf("%f", &d1.inch);
	
	printf("Enter information for 2nd distance: \n");
	printf("Enter feet: ");
	scanf("%d", &d2.feet);
	printf("Enter inch: ");
	scanf("%f", &d2.inch);
	
	FeetSum = d1.feet + d2.feet;
	InchSum = d1.inch + d2.inch;
	
	while(InchSum >= 12)
	{
		InchSum -= 12;
		FeetSum += 1;
	}
	printf("\nSum of distance = %d\' %f\"", FeetSum, InchSum);
	
}

void SumComplexNum(void)
{
	struct complex c1, c2;
	
	printf("For 1st complex number\nEnter real and imaginary respectively: ");
	scanf("%lf %lf", &c1.real, &c1.img);
	
	printf("\nFor 2nd complex number\nEnter real and imaginary respectively: ");
	scanf("%lf %lf", &c2.real, &c2.img);
	
	printf("Sum = %lf + %lfi", c1.real + c2.real, c1.img + c2.img);
}

void DisplayInfoArr(void)
{
	struct student Arr[DisplayInfoArrSize]; int i;
	
	for(i = 0; i < DisplayInfoArrSize; i++)
	{
		printf("Enter name: ");
		gets(Arr[i].Name);
		printf("Enter roll number: ");
		scanf("%d", &Arr[i].rollNum);
		printf("Enter marks: ");
		scanf("%f", &Arr[i].mark);
		fflush(stdin);
			
	}
	
	printf("\nDisplaying information of students: \n");
		
	for(i = 0; i < DisplayInfoArrSize; i++)
	{
		printf("\n\nname: %s\n", Arr[i].Name);
		printf("Roll: %d\n", Arr[i].rollNum);
		printf("Marks: %.3f",Arr[i].mark);
			
	}
	
}
