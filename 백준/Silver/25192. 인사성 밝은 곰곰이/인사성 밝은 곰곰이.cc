#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	set<string> v;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str.compare("ENTER") == 0)
		{
			v.clear();
		}
		else
		{
			if (v.count(str) == 0)
			{
				v.insert(str);
				count++;
			}
		}
	}

	cout << count;
}