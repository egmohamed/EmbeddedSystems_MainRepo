#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n]; int seCount = 0; int diCount = 0;
    int it = 0;

    for(int i = 0; i <n; i++)
    cin>>arr[i];
    int i,j;

   for( i = 0,  j = n - 1; i <= j; it++)
   {
       if(arr[i] > arr[j])
       {
           if(it %2 == 0)
           {
               seCount += arr[i];
           }
           else
           {
               diCount += arr[i];
           }

           i++;
       }
       else
       {
            if(it %2 == 0)
           {
               seCount += arr[j];
           }
           else
           {
               diCount += arr[j];
           }

           j--;
       }


   }
   
   cout<<seCount<< " "<<diCount;

}
