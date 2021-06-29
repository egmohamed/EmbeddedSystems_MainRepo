#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a1,a2,a3,a4;
    cin>>a1;
    cin>>a2;
    cin>>a3;
    cin>>a4;
    cin.ignore();

    int count = 0;

    string s;
    cin>>s;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') count += a1;
        else if(s[i] == '2') count += a2;
        else if(s[i] == '3') count += a3;
        else if(s[i] == '4') count += a4;
    }

    cout<<count;

}
