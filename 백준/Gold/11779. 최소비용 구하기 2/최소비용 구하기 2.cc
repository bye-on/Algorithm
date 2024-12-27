#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[1001];
int d[1001];
int path[1001];
int INF = 0x7000000;

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	d[start] = 0;
	pq.push({ start,0 });

	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (distance > d[current]) continue;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].first;
			int nextDistance = v[current][i].second + distance;

			if (d[next] > nextDistance)
			{
				d[next] = nextDistance;
				path[next] = current;
				pq.push({ next, -nextDistance });
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
		path[i] = 0;
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

	path[start] = 0;
	int index = end;
	vector<int> answer;

	while (true)
	{
		if (path[index] == 0)
		{
			answer.push_back(start);
			break;
		}
		answer.push_back(index);
		index = path[index];
	}

	reverse(answer.begin(), answer.end());

	cout << d[end] << '\n';
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
}