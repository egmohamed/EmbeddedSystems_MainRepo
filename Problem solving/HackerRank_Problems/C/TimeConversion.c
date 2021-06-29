#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the timeConversion function below.
 */

/*
 * Please either make the string static or allocate on the heap. For example,
 * static char str[] = "hello world";
 * return str;
 *
 * OR
 *
 * char* str = "hello world";
 * return str;
 *
 */
char* timeConversion(char* s) {
    /*
     * Write your code here.
     */
     static char str[9]; int i;
    if(s[8] == 'A'){
       if(s[0] == '1' && s[1] == '2'){
           str[0] = '0'; str[1] = '0';
       }
        if(s[0] == '1' && s[1] == '1'){
            str[0] = '1'; str[1] = '1';
        }
        if(s[0] == '1' && s[1] == '0'){
            str[0] = '1'; str[1] = '0';
        }

        switch(s[1]){
                case '1': if(s[0] !='0')break;str[0]='0'; str[1] = '1'; break;
                case '2': if(s[0] !='0')break;str[0]='0'; str[1] = '2'; break;
                case '3': str[0]='0'; str[1] = '3'; break;
                case '4': str[0]='0'; str[1] = '4'; break;
                case '5': str[0]='0'; str[1] = '5'; break;
                case '6': str[0]='0'; str[1] = '6'; break;
                case '7': str[0]='0'; str[1] = '7'; break;
                case '8': str[0]='0'; str[1] = '8'; break;
                case '9': str[0]='0'; str[1] = '9'; break;
        }
    }
    else if(s[8] == 'P'){
         if(s[0] == '1' && s[1] == '2'){
           str[0] = '1'; str[1] = '2';
          }
        if(s[0] == '1' && s[1] == '1'){
            str[0] = '2'; str[1] = '3';

          }
        if(s[0] == '1' && s[1] =='0'){
            str[0] = '2'; str[1] = '2';

          }
        switch(s[1]){
                case '1': if(s[0] !='0')break;str[0]='1'; str[1] = '3'; break;
                case '2': if(s[0] !='0')break;str[0]='1'; str[1] = '4'; break;
                case '3': str[0]='1'; str[1] = '5'; break;
                case '4': str[0]='1'; str[1] = '6'; break;
                case '5': str[0]='1'; str[1] = '7'; break;
                case '6': str[0]='1'; str[1] = '8'; break;
                case '7': str[0]='1'; str[1] = '9'; break;
                case '8': str[0]='2'; str[1] = '0'; break;
                case '9': str[0]='2'; str[1] = '1'; break;
        }
    }
    for(i = 2;i<8;i++)
        str[i] = s[i];

    return str;

}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

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
