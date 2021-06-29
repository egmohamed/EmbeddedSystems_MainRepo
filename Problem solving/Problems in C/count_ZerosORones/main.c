#include <stdio.h>
#include <stdlib.h>
/*
//count zeros,ones in integer number
int main()
{
    int temp;int count0,count1,i =0;
    char arr[10]; char ch;
    printf("Enter number : ");

    while (ch != '\n'){
        ch = getchar();
        arr[i] = ch;
        if(ch == '0')
          count0++;
            else if (ch == '1')
            count1++;
           // printf("%d \n",count1);
    }
      printf("Count of zeros = %d \nCount of ones = %d ",count0-87,count1-8);

    return 0;
}
*/



// count zeros,ones in binary number
int main()
{
    int n;
    int count1 =0;
    int count0 =0;
    int i= 0;
    int j;
    int binaryNum[1000];
    printf("Enter number to convert it to binary : ");

    scanf("%d",&n);

    while (n > 0) {

        binaryNum[i] = n % 2;
        n = n / 2;
        if (binaryNum[i] == 1)
            count1++;
         else
            count0++;
        i++;

    }


    for ( j = i - 1; j >= 0; j--)
        printf("%d",binaryNum[j]);

printf("\nnumber of zeros = %d \n",count0);
printf("number of ones = %d",count1);

return 0;
}


