#include <iostream>
using namespace std;

int map[1001][1001];
int main()
{
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			if (a[i] == b[j])
				map[i + 1][j + 1] = map[i][j] + 1;
			else
				map[i + 1][j + 1] = max(map[i + 1][j], map[i][j + 1]);
		}
	}

	int max = 0;
	for (int i = 0; i <= a.length(); i++)
	{
		for (int j = 0; j <= b.length(); j++)
		{
			if (map[i][j] > max)
				max = map[i][j];
		}
	}

	cout << max;
}