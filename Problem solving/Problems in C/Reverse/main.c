#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;   int i;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    char arr[size];
    printf("Enter array elements to print them in reverse order : \n");
    for(i = 0;i<size;i++)
        scanf(" %c",(arr+i));
         printf("Array in reversed order : \n");
        reverse(arr,size);

    return 0;
}
/*

// leh hena law 3malt el function char * type we 3mlt return arr2 bytl3 7gat 8lat we lama a3mel return arr1 bytl3 sa7 3ady ?
// hal momken n3mel reverse lel elements fe nafs el array ?

int* func(int x){
int *y;
*y = 5;
x = 4;
return y;
}
int main(){
    int num;
  // scanf("%d",&num);
    int *z = func(7);
    printf("%d",*z));
return 0;
}
*/
// leh hena lama bt5aly el value eli hatbaseha lel func brqm we t3ml return y mabyrda4 ?
