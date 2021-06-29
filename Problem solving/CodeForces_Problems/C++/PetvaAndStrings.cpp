#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s1; string s2;
    
    cin>>s1>>s2;
   
    for(int i = 0; i <s1.size(); i++)
    {
        if(s1[i] < 97)
        {
            s1[i] += 32;
        }
    }
    
    
     for(int i = 0; i <s2.size(); i++)
    {
        if(s2[i] < 97)
        {
            s2[i] += 32;
        }
    }
    
    if(s1 < s2)
    cout<<-1;
    else if(s2 < s1)
    cout<<1;
    else
    cout<<0;
    
}