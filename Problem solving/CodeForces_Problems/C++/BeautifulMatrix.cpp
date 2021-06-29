#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i; int num[5][5];
    int res = 0;
    
    for(i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin>>num[i][j];
            
            if(num[i][j] == 1)
            {
                res = abs(i - 2) + abs(j - 2);
            }
        }
    }
    
   cout<<res;
    
    
}