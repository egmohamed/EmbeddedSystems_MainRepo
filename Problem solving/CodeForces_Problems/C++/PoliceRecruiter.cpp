#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int count = 0;
    int res = 0;
    int j;
    
    for(int i = 0; i <n; i++)
    cin>>arr[i];
    
    for(int i = 0; i <n; i++)
    { 
        if(arr[i] != -1 )
        {

            for(j = i; j < n && arr[j] != -1; j++)
            {
                if(count < 0)
                {
                     count = 0;
                }
                
                 count += arr[j];
            }
            i = j - 1;
            continue;
            
        }
        
        count += arr[i];
        
        if(count < 0)
        {
            res++;
        }
    }
    
    cout<<res;
}