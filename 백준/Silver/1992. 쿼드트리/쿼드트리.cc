#include <iostream>
using namespace std;

int map[65][65];

bool OK(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (map[x][y] != map[i][j])
				return false;
		}
	}
	return true;
}

void QuadTree(int x, int y, int n)
{
	if (n <= 0)
		return;

	if (!OK(x, y, n))
	{
		cout << "(";
		QuadTree(x, y, n / 2);
		QuadTree(x, y + (n / 2), n / 2);
		QuadTree(x + (n / 2), y, n / 2);
		QuadTree(x + (n / 2), y + (n / 2), n / 2);
		cout << ")";
	}
	else
	{
		cout << map[x][y];
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < input.length(); j++)
		{
			map[i][j] = input[j] - '0';
		}
	}

	QuadTree(0, 0, n);
}