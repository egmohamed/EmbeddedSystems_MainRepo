#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char arr[26];
    for(i = 0;i<26;i++){
    *(arr+i) = 97+i;
    printf("%c ",*(arr+i));
    }
    return 0;
}
