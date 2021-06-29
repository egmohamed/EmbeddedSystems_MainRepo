#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* pangrams(char* s)
{
	char arr[200] = {0}; static char res[11];
	int i;
	for(i = 0; i<strlen(s); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
            arr[i] = s[i] - 96;

            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                arr[i] = s[i] - 64;
            }
	}
	for(i = 0; i<26; i++)
    {
        if(arr[i] == 0)
        {
            strcpy(res,"not pangram");
            return res;
        }
    }

    strcpy(res,"pangram");
    return res;


}

int main()
{
    char *result;

	char s[] = "abcdefghijklmnopqrstuvwxyz";	// The array

	result = pangrams(s);
    printf("%s", result);	// The result must be "not pangram"

    return 0;
}

