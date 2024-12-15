#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int d[1001][1001];
int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		d[a][b] = t;
	}

	
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (d[i][k] == INF)
				continue;

			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int time = 0;
	for (int i = 1; i <= n; i++)
	{
		time = max(time, d[i][x] + d[x][i]);
	}

	cout << time;
}