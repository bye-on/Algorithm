#include <iostream>
using namespace std;

int INF = 1e9;
int d[100][100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = INF;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;
			if(input != 0)
				d[i][j] = input;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] < INF)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << '\n';
	}
}