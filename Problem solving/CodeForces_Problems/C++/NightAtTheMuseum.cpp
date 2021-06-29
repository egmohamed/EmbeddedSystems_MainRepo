#include <iostream>
#include <string>

using namespace std;

int main()
{
	int st;
	string s;
	cin >> s;
	char arr[26]; int j; int i; int inc = 0;
	int countR = 0, countL = 0; int res = 0;
	for ( i = 26 / 2, j = 0; i < 26 && j < 26/2; i++, j++)
	{
		arr[i] = 'a' + inc;
		arr[j] = 'a' + i;
		inc++;
	}
	int m = 26 / 2, n = 26 / 2;
	for (int i = 0; i < s.size(); i++)
	{		
		for (int j = m; j < 26; j++)
		{

			if (s[i] == arr[j])
			{
				m = j;
				break;
			}

			if (j == 25)
			{
				j = -1;
			}
			
			countR++;
		}

		for (int k = n; k >= 0; k--)
		{

			if (s[i] == arr[k])
			{
				n = k;
				break;
			}
			
			if (k == 0)
			{
				k = 26;
			}

			countL++;
		}

		if (countL < countR)
		{
			res += countL;		
		}
		else
		{
			res += countR;		
		}
		countL = 0;
		countR = 0;

	}
	cout << res;
	
}
