#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int INF = 1e9;

vector<int> v[101];
int d[101];
int depth = 0;

void bfs(int n)
{
	queue<int> q;
	depth = 0;
	d[n] = depth;
	q.push(n);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		depth = d[current] + 1;

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i];
			if (d[next] > depth)
			{
				d[next] = depth;
				q.push(next);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	priority_queue<pair<int, int>> cnt;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[j] = INF;
		}

		bfs(i);

		int count = 0;
		for (int j = 1; j <= n; j++)
		{
			count += d[j];
		}
		cnt.push({ -count, -i });
	}

	cout << -cnt.top().second;
}