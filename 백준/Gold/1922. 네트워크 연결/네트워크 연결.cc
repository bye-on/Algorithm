#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;
int parent[1001];

int find_parent(int x)
{
	if (parent[x] != x)
		parent[x] = find_parent(parent[x]);

	return parent[x];
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ -c, {a,b} });
	}

	int result = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;

		int a = pq.top().second.first;
		int b = pq.top().second.second;

		pq.pop();

		if (find_parent(a) != find_parent(b))
		{
			union_parent(a, b);
			result += cost;
		}
	}

	cout << result;
}