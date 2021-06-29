
int FindMin(int arr[],int size,int start){
    int i; int imin = start;
for(i = start;i<size;i++){
  if(arr[i] < arr[imin])
            imin = i;
}
return imin;
}
