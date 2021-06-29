#include "HomeWork6.h"

void pointerHandle (void)
{
	int m = 29; int* ab;
	printf("\nAddress of m : %x\n", &m);
	printf("Value of m : %d\n", m);
	
	ab = &m;
	printf("Now ab is assigned with the address of m.\n\
Address of pointer ab : %x\nContent of pointer ab : %d\n", ab, *ab);
	
	m = 34;
	
	printf("The value of m assigned to 34 now.\nAddress \
of pointer ab : %x\nContent of pointer ab : %d\n", ab, *ab);
			
	*ab = 7;
	
	printf("The pointer variable ab is assigned with the value \
7 now.\nAddress of m : %x\nValue of m : %d", &m, m);
}

void printAlphabets (void)
{
	char* alphPtr; char alph = 'A'; int i;
	
	printf("\nThe Alphabets are: \n\n");
	
	alphPtr = &alph;
	
	for(i = 0; i < 26; i++)
		printf("%c ", (*alphPtr) + i);
	
	
}

void strReverse (char* str)
{
	if(*str == '\0')
		return;
	
	strReverse(str + 1);
	printf("%c", *str);
}

void reverseArrElements (void)
{
	int arrSize; int i; int arr[15] = {0};
	printf("Input the number of elements to store in the array (max 15) : ");
	
	scanf("%d", &arrSize);
	printf("Input 5 number of elements in the array : \n");
	
	for(i = 0; i < arrSize; i++)
	{
		printf("element-%d:", i + 1);
		scanf(" %d", &arr[i]);
	}
	
	printf("The elements of array in reverse order are :\n");
	
	for(i = arrSize - 1; i >= 0; i--)
	{
		printf("element - %d : %d\n", i + 1, arr[i]);
	}
		
}

void pointer2ArrStruct (void)
{	
	struct Employee empObj;
	struct Employee* Sptr = &empObj;
	struct Employee* arr[3] = {Sptr};
	struct Employee* (*ptr)[3] = &arr;
	
	(**ptr)->empName = "Alex";
	(**ptr)->empID = 1002;
	
	printf("Employee Name: %s\nEmployee ID: %d", (*ptr)[0]->empName, (*ptr)[0]->empID);
}