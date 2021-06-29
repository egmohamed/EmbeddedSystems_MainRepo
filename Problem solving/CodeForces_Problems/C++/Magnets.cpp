#include <iostream>
using namespace std;

int main()
{
   int n; int count = 1; int res = 0;
   cin>>n;
   string arr[n];
   
   for(int i = 0; i < n; i++)
   {
       cin>>arr[i];
   }
   
   if(n == 1)
   {
       res = 1;
       cout<<res;
       return 0;
   }
   
   for(int i = 0; i <n; i++)
   {
       if((arr[i][0] != arr[i-1][0]) && (i != 0))
       {
           count++;
       }
   }
   
   res = count;
   cout<<res;

}
