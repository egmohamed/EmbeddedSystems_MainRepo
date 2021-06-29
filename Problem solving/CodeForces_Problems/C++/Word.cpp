#include <iostream>
using namespace std;
#include <string>
int main()
{
   string s;
   cin>>s;
   int countup = 0;
   int countlo = 0;
   
   for(int i = 0; i<s.size(); i++)
   {
       if(s[i] >= 'a' && s[i] <= 'z')
       {
           countlo++;
       }
       else
       {
           countup++;
       }
   }
   
   if(countup > countlo)
   {
       for(int i = 0; i < s.size(); i++)
       {
           if(s[i] >= 'a' && s[i] <= 'z')
           {
               s[i] -= ('a' - 'A');
           }
       }
   }
   else 
   {
       for(int i = 0; i < s.size(); i++)
       {
           if(s[i] >= 'A' && s[i] <= 'Z')
           {
               s[i] += ('a' - 'A');
           }
       }
   }
   
   cout<<s;

}
