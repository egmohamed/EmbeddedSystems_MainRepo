#include <iostream>

using namespace std;

int main()
{
    int n, p1 = 0,p2 = 0;
    char ch;
    cin>>n;
    
    while(n)
    {
        cin>>ch;
        if(ch == 'A')
        {
            p1++;
        }
        else if(ch == 'D')
        {
            p2++;
        }
        
        n--;
    }
    
    if(p1 > p2)
    {
        cout<<"Anton";
    }
    else if (p2 > p1)
    {
        cout<<"Danik";
    }
    
    else
    {
        cout<<"Friendship";
    }
}