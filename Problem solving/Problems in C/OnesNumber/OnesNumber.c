#include <stdio.h>

int OnesNumber(int num);

int main()
{
	int input = 5;
	int res = OnesNumber(input);
	printf("Ones count in %d = %d", input, res);
	
	input = 15;
	res = OnesNumber(input);
	printf("\nOnes count in %d = %d", input, res);
}

int OnesNumber(int num)
{
	int count = 0;
	
	while(num)
	{
		num &= num - 1;
		count++;
	}
	
	return count;
}