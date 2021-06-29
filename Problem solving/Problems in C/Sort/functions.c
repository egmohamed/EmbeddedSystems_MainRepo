#include<stdio.h>
#include<stdlib.h>

int *sort(int a[],int n){
int i; int j; int imin;
for(i = 0; i<n-1 ;i++){
    imin = i;
    for(j =i; j<n; j++){
        if(a[j] < a[imin])
            imin = j;
    }
    swap(a,i,imin);
    }
return a;
}

void swap(int a[],int i,int imin){
int temp;
temp = a[i];
a[i] = a[imin];
a[imin] = temp;

}
