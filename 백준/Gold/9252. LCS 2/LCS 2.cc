#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[1001][1001];
int main()
{
	string a;
	string b;
	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1]) map[i][j] = map[i - 1][j - 1] + 1;
			else map[i][j] = max(map[i][j - 1], map[i - 1][j]);
		}
	}

	vector<char> v;
	int i = a.size(); int j = b.size();
	int current = map[i][j];

	while (i > 0 && j > 0)
	{
		if (map[i - 1][j] == current)
		{
			i--;
		}
		else if (map[i][j - 1] == current)
		{
			j--;
		}
		else
		{
			i--; j--;
			v.push_back(a[i]);
			current = map[i][j];
		}
	}

	cout << v.size() << '\n';
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
}