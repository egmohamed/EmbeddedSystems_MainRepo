#include <stdio.h>

/* Ex1 */
void PrintSentence(void);

/* Ex2 */
void PrintNumber(void);

/* Ex3 */
void AddTwoIntegers(void);

/* Ex4 */
void MultiplyTwoFloats(void);

/* Ex5 */
void FindAsciiValue(void);

/* Ex6 */
void Swap(void);

/* Ex7 */
void TrickySwap(void);

int main(void)
{
 /*
	PrintSentence();
	PrintNumber();
	AddTwoIntegers();
	MultiplyTwoFloats();
	FindAsciiValue();
	Swap();
 */
	TrickySwap();
	return 0;
}

void PrintSentence(void)
{
	printf("C Programming");
}

void PrintNumber(void)
{
	int num;

	printf("Enter an integer: ");

	/* fflush function is used frequently in eclipse projects due to
	 * the buffer bug
	 */

	fflush(stdout);
	scanf("%d", &num);
	printf("You entered: %d", num);

}

void AddTwoIntegers(void)
{
	int num1, num2;

	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d %d", &num1, &num2);
	fflush(stdin);
	printf("Sum: %d", num1 + num2);

}

void MultiplyTwoFloats(void)
{
	float num1, num2;

	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f %f", &num1, &num2);
	fflush(stdin);
	printf("Product: %f", num1 * num2);
}

void FindAsciiValue(void)
{
	char ch;

	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c", &ch);
	printf("ASCII Value of %c = %d", ch, ch);
}

void Swap(void)
{
	float a,b;
	float temp;

	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f", &a);
	fflush(stdin);

	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f", &b);

	printf("\n");

	temp = a;
	a = b;
	b = temp;

	/* in order to show the output numbers as specified in the assignment
	 * requirements, %.2f added to show the float number fraction in two digits
	 * only. Note: with numbers of more than two digits in precision
	 * like 2.445656 the output will not be accurate
	 */

	printf("After swapping, value of a = %.2f \n", a);
	printf("After swapping, value of b = %.2f \n", b);

}

void TrickySwap(void)
{
	float a,b;

	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f", &a);
	fflush(stdin);

	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f", &b);

	printf("\n");

	/* Note: we can also use a = a*b; b = a/b; a = a/b; to swap the variables
	 * also we can use this method: a = a^b; b = a^b; a = a^b; but the latter
	 * method can't be applied on floats as in this function
	 */

	a = a + b;
	b = a - b;
	a = a - b;

	/* in order to show the output numbers as specified in the assignment
	 * requirements, %.2f added to show the float number fraction in two digits
	 * only. Note: with numbers of more than two digits in precision
	 * like 2.445656 the output will not be accurate
	 */

	printf("After swapping, value of a = %.2f \n", a);
	printf("After swapping, value of b = %.2f \n", b);
}

