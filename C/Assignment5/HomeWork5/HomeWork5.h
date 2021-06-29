#ifndef __HOME_WORK5_H_
#define __HOME_WORK5_H_

#include <stdio.h>

#define PI 3.14159265359
#define CircleArea(r) (PI *(r)*(r))
#define DisplayInfoArrSize	3

struct student
{
	char Name[40];
	int rollNum;
	float mark;
};

struct distance
{	
	int feet;
	float inch;
};

struct complex
{
	double real;
	double img;
};

void DisplayStudentInfo(void);
void SumDistance(void);
void SumComplexNum(void);
void DisplayInfoArr(void);

#endif