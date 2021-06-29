int *bubbleSort(int arr[],int n){
int i; int current = 0; int j;
for(current = 0;current<n;current++){
    for(j = current;j<n;j++){
        if(arr[current]>arr[j])
            swap(arr,current,j);
    }

}
return arr;
}

void swap(int a[],int current,int j){
int temp;
temp = a[j];
a[j] = a[current];
a[current] = temp;

}
