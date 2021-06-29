#include <iostream>
using namespace std;

int main()
{
    string s; int count = 0;

    cin>>s;
    static char temp[26];
    for(int i = 0; i < s.size(); i++)
    {
        temp[s[i] - 97] += 1;
    }

    for(int i = 0; i < 26; i++)
    {
        if(temp[i] >= 1)
        {
            count++;
        }
    }

    if(count %2 == 0)
    cout<<"CHAT WITH HER!";
    else
    cout<<"IGNORE HIM!";

}
