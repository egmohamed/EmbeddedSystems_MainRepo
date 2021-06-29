#include <stdio.h>
#include <limits.h>

int MaxOnesBetweenTwoZeros(int num);

int main()
{
	int input = 14;
	int res = MaxOnesBetweenTwoZeros(input);
	printf("Max ones between two zeros for the input: %d = %d", input, res);
	
	input = 110;
	res = MaxOnesBetweenTwoZeros(input);
	printf("\nMax ones between two zeros for the input: %d = %d", input, res);
}

int MaxOnesBetweenTwoZeros(int num)
{
	int count = 0; int max = INT_MIN;
	int visitZero = 0; int ind = 0;
	
	while(1)
	{
		if((1 & num) == 1)
		{
			count++;
		} 
		else
		{
			visitZero++;
			
			if(count > max && visitZero == 2)
			{
				max = count;
				visitZero = 1;
			}
			count = 0;
		}
				
		num = num >> 1;
		if(num == 0)
		{
			ind++;
		}
		
		if(ind == 2)
			break;
	}
	
	if(max == INT_MIN)
		return count;
	
	return max;
}