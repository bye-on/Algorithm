#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s, t;
	while (cin >> s >> t)
	{
		int index = 0;
		for (int i = 0; i < t.size(); i++)
		{
			if (s[index] == t[i])
			{
				index++;
				if (index == s.size())
					break;
			}
		}

		
		if (index == s.size())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}