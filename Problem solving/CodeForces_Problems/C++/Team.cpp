#include <iostream>

using namespace std;

int main()
{
    
    int n;
    cin>>n;
    int first, second, third, count = 0;
    int arr[3];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[0]>>arr[1]>>arr[2];
        
        if(arr[0] + arr[1] + arr[2] >= 2 )
        {
            count++;
        }
    }
    
    cout<< count;
}