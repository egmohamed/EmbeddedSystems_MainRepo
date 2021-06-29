#include "HomeWork3.h"

void TwoMatrixSum(void)
{
    float firstMat[2][2], secondMat[2][2];
    int i, j;

    printf("Enter the elements of 1st matrix: \n");

    for(i = 0; i < 2; i++)
    {
         for(j = 0; j < 2; j++)
         {
              printf("Enter a%d%d: ", i+1, j+1);
              scanf("%f", &firstMat[i][j]);
              fflush(stdin);
         }
    }

    printf("\n");

    printf("Enter the elements of 2nd matrix: \n");

    for(i = 0; i < 2; i++)
    {
         for(j = 0; j < 2; j++)
         {
              printf("Enter b%d%d: ", i+1, j+1);
              scanf("%f", &secondMat[i][j]);
              fflush(stdin);
         }
    }

    printf("\n");

    printf("Sum of matrix: \n");

    for(i = 0; i < 2; i++)
    {
         for(j = 0; j < 2; j++)
         {
             if(i == 1 && j == 0)
             {
                 printf("\n");
             }

             printf("%f     ", firstMat[i][j] + secondMat[i][j]);

         }
    }

}

void AvgNumbers(void)
{
    int n, i; float sum = 0.0;

    printf("Enter the numbers of data: ");
    scanf("%d", &n);

   /* This is one of methods to create an array with user input length
    * alternatively, we can create a static array with maximum expected
    * size but there will be a lot of memory loss if the user entered
    * a small length or we can compile with std=99 option to allow dynamic
    * size arrays. We can also solve this problem without using an
    * array. However this option is not the goal of this problem which aims
    * to use it
    */
    float* arr = (float*) malloc(n * sizeof(float));

    for(i = 0; i < n; i++)
    {
        printf("%d. Enter number: ", i+1);
        scanf("%f", &arr[i]);
        fflush(stdin);

        sum += arr[i];
    }

    printf("Average = %f", sum/n);

}

void MatrixTranspose(void)
{
    int row, col, i, j;

    printf("Enter rows and columns of matrix: ");
    scanf("%d", &row);
    fflush(stdin);
    scanf("%d", &col);

   /* 2D array dynamically allocated. To use variable size 2D array, we can also
    * compile with std=c99 or assume a big size of memory and allocate it statically
    */
    int** Matrix = (int**)malloc(row * sizeof(int*));

    for(i = 0; i < row; i++)
    {
        Matrix[i] = (int*)malloc(col * sizeof(int));
    }

     printf("\nEnter elements matrix: \n");

    for(i = 0; i < row; i++)
    {
         for(j = 0; j < col; j++)
         {
              printf("Enter a%d%d: ", i+1, j+1);
              scanf("%d", &Matrix[i][j]);
              fflush(stdin);
         }
    }

    printf("\nEntered matrix: ");

     for(i = 0; i < row; i++)
     {
         printf("\n");

         for(j = 0; j < col; j++)
         {

             printf("%d   ", Matrix[i][j]);

         }
     }

     printf("\n\nTranspose of matrix: ");

     for(i = 0; i < col; i++)
     {
         printf("\n");

         for(j = 0; j < row; j++)
         {
             printf("%d   ", Matrix[j][i]);

         }
     }

}

void ArrayInsert(void)
{
    int n, i, ins, loc;

    printf("Enter no of elements : ");
    scanf("%d", &n);

   /* allocate additional memory for the number to be inserted
    * Note that in case of multiple insertions in one run, the
    * array size won't be sufficient and you may need to reallocate
    * the array size each increment or each number of increments.This
    * is applicable in c by using realloc function
    */
    int* arr = (int*) malloc((n+1) * sizeof(int));

    for(i = 1; i <= n; i++)
    {
        printf("%d ", i);
        arr[i - 1] = i;
    }

    printf("\nEnter the element to be inserted : ");
    scanf("%d", &ins);
    printf("Enter the location : ");
    scanf("%d", &loc);

    for(i = n; i>= loc; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[loc - 1] = ins;

    for(i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

}

void SearchInArray(void)
{
    int n, i = 0; int long num = 0;
    int searchNum;
    char Str[200]; char* tok;
    char* ptr;

    printf("Enter number of elements: ");
    scanf("%d ", &n);

    //multiplied by two to add more memory for space characters
    int long* arr = (int long*)malloc(n * sizeof(int long));

    /* assumed the input to be numbers with space char between each of them
     * (in order to match the sample of input data given in the requirements)
     */
    fgets(Str, 200, stdin);
    tok = strtok(Str, " ");

    while(tok != NULL)
    {
        /* atoi also can be used here and it's preferred for old standard c versions */
        num = strtol(tok, &ptr, 0);
        arr[i] = num;
        tok = strtok(NULL, " ");
        i++;
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &searchNum);

   /* This is a linear search with time complexity of O(n). Better algorithms can also
    * be used for huge number entries like binary search with O(log(n)) in time complexity
    */
    for(i = 0; i < n; i++)
    {
         if(arr[i] == searchNum)
         {
             printf("Number found at the location = %d\n", i+1);
         }
    }

}

void CharsFrequency(void)
{
    char ch; int count = 0, i;
    char Str[100];

    /* We can also write char by char like in my implementation for StrLen function
     * and store them in an array or we can use gets() function. Note that gets function
     * is unsafe and dangerous to use in real projects and has been deprecated in c11 standard due
     * to it's buffer overflow problem
     */
    printf("Enter a string: ");

    /* input string should not exceed 100 character */
    fgets(Str, 100, stdin);

    printf("Enter a character to find frequency: ");
    scanf("%c", &ch);

    for(i = 0; Str[i]; i++)
    {
        if(Str[i] == ch)
            count++;
    }
    printf("Frequency of %c = %d", ch ,count);
}

void StrLen(void)
{
    int count = -1; char ch;
    printf("Enter a string: ");

    /* We can also store the input in array and counts it's members until
     * we reach to the null character
     */
    while(ch != '\n')
    {
        ch = getchar();
        count++;
    }
    printf("Length of string: %d", count);
}

void StrReverse(void)
{
    char Str[200]; int i = 0;
    printf("Enter the string: ");

    fgets(Str,200, stdin);

    while(Str[i])
        i++;

    /* In this example we just show the characters in reversed order. This is
     * not an actual reversing of the array. However if you want so, you can
     * swap the first array half with the second array half to reverse it
     */
    printf("Reverse string is: ");

    for(; i >= 0; i--)
        printf("%c", Str[i]);
}
