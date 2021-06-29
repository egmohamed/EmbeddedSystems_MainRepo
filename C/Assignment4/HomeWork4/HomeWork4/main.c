#include "HomeWork4.h"
#define ON      1
#define OFF     0

/*Please set the program you want to run to "ON" value*/

#define Ex1     OFF
#define Ex2     ON
#define Ex3     OFF
#define Ex4     OFF

int main()
{

    #if Ex1

    PrimeNumInterval();

    #endif  //  Ex1

    #if Ex2

    int num1;

    printf("Enter a positive integer: ");
    scanf("%d", &num1);

    int res2 = RecursionFac(num1);

    printf("Factorial of %d = %d", num1, res2);

    #endif // Ex2

    #if Ex3

    printf("Enter a sentence: ");

    char StrArr[] = "Mohamed Hosny";

    fgets(StrArr, 100, stdin);

    RecursionRevStr(StrArr);

    #endif // Ex3

    #if Ex4

    int Base, Pow;

    printf("Enter Base number: ");
    scanf("%d",&Base);
    printf("Enter power number(positive integer): ");
    scanf("%d", &Pow);
    printf("%d^%d = ",Base, Pow);
    printf("%d", RecursionNumPow(Base, Pow));

    #endif // Ex4

    return 0;
}
