#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[1001];
int d[1001];
int INF = 1e9;

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	d[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (d[current] < distance) continue;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].first;
			int next_distance = distance + v[current][i].second;

			if (d[next] > next_distance)
			{
				d[next] = next_distance;
				pq.push({ next, -next_distance });
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
	}

	for (int i = 0; i < m; i++)
	{	
		int a, b, t;
		cin >> a >> b >> t;
		v[a].push_back({ b,t });
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start);
	cout << d[end];
}