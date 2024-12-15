#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int d[1001];
int INF = 1e9;
vector<pair<int, int>> start[1001];
vector<pair<int, int>> finish[1001];

void dijkstra(vector<pair<int, int>> v[1001], int target)
{
	priority_queue<pair<int, int>> pq;
	d[target] = 0;
	pq.push({ target,0 });

	while (!pq.empty())
	{
		int node = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (d[node] < distance) continue;

		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i].first;
			int nextDistance = distance + v[node][i].second;

			if (d[next] > nextDistance)
			{
				d[next] = nextDistance;
				pq.push({ next, -nextDistance });
			}
				
		}
	}
}

int main()
{
	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;

		start[a].push_back({ b, t });
		finish[b].push_back({ a,t });
	}

	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
	}
	dijkstra(start, x);

	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(d[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
	}

	dijkstra(finish, x);

	int maxNum = 0;
	for (int i = 0; i < n; i++)
	{
		maxNum = max(maxNum, (v[i] + d[i + 1]));
	}

	cout << maxNum;
}