#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the minimumNumber function below.
int minimumNumber(int n, char* password) {
    // Return the minimum number of characters to make the password strong

     int i;
    unsigned char IsUpper = 0; unsigned char IsLower = 0; unsigned char IsSpecial = 0;       unsigned char IsDigit = 0;
    unsigned char ExceedSix = 0; unsigned char count = 0;

    for(i = 0; i < n; i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {

            IsDigit++;
        }

        if(password[i] >= 'a' && password[i] <= 'z')
        {
            IsLower++;
        }

        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            IsUpper++;
        }

        if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i]          == '$' || password[i] == '%'
           || password[i] == '^' || password[i] == '&' || password[i] == '*' || password            [i] == '(' || password[i] == ')'
           || password[i] == '-' || password[i] == '+' )
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

    if(n + count >= 6)
    {
        return count;
    }

    else
    {
        return (count + (6 - (count + n)));
    }

}



int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* password = readline();

    int answer = minimumNumber(n, password);

    fprintf(fptr, "%d\n", answer);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
