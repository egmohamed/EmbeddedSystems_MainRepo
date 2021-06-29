#include <stdio.h>
#include <stdlib.h>
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
    char arr[9] = {'1','2',':','0','5',':','4','5','P','M'};
    char *res = timeConversion(arr);
    printf("%s",res);
    return 0;
}
