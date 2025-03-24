#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string a, string b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return true;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	vector<string> result;
	for (int index = 0; index < v.size(); index++)
	{
		if (result.empty())
			result.push_back(v[index]);
		else
		{
			bool ok = true;

			for (int i = 0; i < result.size(); i++)
			{
				for (int j = 0; j < result[i].size(); j++)
				{
					if (!check(result[i], v[index]))
						ok = false;
				}
			}

			if (ok)
				result.push_back(v[index]);
			else
			{
				result.pop_back();
				result.push_back(v[index]);
			}
		}
	}

	cout << result.size();
}