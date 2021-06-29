#include<stdio.h>
#include<stdlib.h>

int StrongPass(int l, char* pass);

int main(void)
{
    char Pass[] = "Ah!0Az2@kjK";
    int res = StrongPass(11,Pass);
    printf("%d", res);
    return 0;
}

int StrongPass(int l, char* pass)
{
    int i;
    unsigned char IsUpper = 0; unsigned char IsLower = 0; unsigned char IsSpecial = 0; unsigned char IsDigit = 0;
    unsigned char ExceedSix = 0; unsigned char count = 0;

    for(i = 0; i < l; i++)
    {
        if(pass[i] >= '0' && pass[i] <= '9')
        {

            IsDigit++;
        }

        if(pass[i] >= 'a' && pass[i] <= 'z')
        {
            IsLower++;
        }

        if(pass[i] >= 'A' && pass[i] <= 'Z')
        {
            IsUpper++;
        }

        if(pass[i] == '!' || pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] == '%'
           || pass[i] == '^' || pass[i] == '&' || pass[i] == '*' || pass[i] == '(' || pass[i] == ')'
           || pass[i] == '-' || pass[i] == '+' )
        {
            IsSpecial++;
        }


    }

    if(IsUpper == 0)
    {
        count++;
    }

    if(IsLower == 0)
    {
        count++;
    }

    if(IsDigit == 0)
    {
        count++;
    }

    if(IsSpecial == 0)
    {
        count++;
    }

    if(l + count >= 6)
    {
        return count;
    }

    else
    {
        return (count + (6 - (count + l)));
    }

}
