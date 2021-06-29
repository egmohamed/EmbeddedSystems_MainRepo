void Merge(int arr[], int low,int high){
int mid;
if(low<high)
{
    mid = (low+high)/2
    Merge(arr,low,mid);
    Merge(arr,mid+1,high);
    coreMerge(arr,low,mid,high);
}
}

void coreMerge(int arr[],int l,int m,int h){
int arr1[10]; int arr2[10];
int n1,n2,i,j,k;
n1 = m-l+1;
n2 = h-m;
for(i =0;i<n1;i++)
    arr[i] = arr[l+i];
for(j = 0;j<n2;j++)
    arr2[j] = arr[m+j+1];
arr1[i] = 9999;
arr2[j] = 9999;
i = 0; j =0;
for(k =l;k<=h;k++){
    if(arr1[i]<arr2[j])
        arr[k] = arr1[i++];
    else if(arr1[i]>arr2[j])
        arr[k] = arr2[j++];

}

}
